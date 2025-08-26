#include <bits/stdc++.h>
#define task "smsts"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 200;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

struct edge
{
    int to, w, id;
};

int n, m;
int sum = 0, cnt = 0;
std::vector<edge> edges;
std::vector<edge> adj[maxn + 7];
int par[maxn + 7], f[maxn + 7], id[maxn + 7];

bool bfs(int s, int t)
{
    std::fill(par, par + n + 1, -1);
    std::fill(f, f + n + 1, 0);
    std::queue<int> q;
    par[s] = s;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto &e : adj[u])
        {
            int v = e.to, w = e.w;
            if (par[v] == -1)
            {
                par[v] = u;
                f[v] = w;
                id[v] = e.id;
                if (v == t)
                {
                    return true;
                }
                q.push(v);
            }
        }
    }
    return false;
}

void del(int u, int v, int idx, int w)
{
    for (auto it = adj[u].begin(); it != adj[u].end(); ++it)
    {
        if (it->to == v && it->id == idx)
        {
            adj[u].erase(it);
            break;
        }
    }
    for (auto it = adj[v].begin(); it != adj[v].end(); ++it)
    {
        if (it->to == u && it->id == idx)
        {
            adj[v].erase(it);
            break;
        }
    }
    sum -= w;
    cnt--;
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    if (std::fopen(task ".inp", "r"))
    {
        std::freopen(task ".inp", "r", stdin);
        std::freopen(task ".out", "w", stdout);
    }

    std::cin >> n >> m;
    
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        std::cin >> u >> v >> w;

        if (u == v)
        {
            if (cnt == n - 1)
            {
                std::cout << sum << "\n";
            }
            else
            {
                std::cout << "123456789\n";
            }
            continue;
        }

        if (!bfs(u, v))
        {
            adj[u].pb({v, w, i});
            adj[v].pb({u, w, i});
            sum += w;
            cnt++;
        }
        else
        {
            int mx = -inf, x = -1, y = -1, mx_id = -1;
            int cur = v;
            while (cur != u)
            {
                if (f[cur] > mx)
                {
                    mx = f[cur];
                    mx_id = id[cur];
                    x = cur;
                    y = par[cur];
                }
                cur = par[cur];
            }
            if (mx > w)
            {
                del(x, y, mx_id, mx);
                adj[u].pb({v, w, i});
                adj[v].pb({u, w, i});
                sum += w;
                cnt++;
            }
        }

        if (cnt == n - 1)
        {
            std::cout << sum << "\n";
        }
        else
        {
            std::cout << "123456789\n";
        }
    }

    return 0;
}
