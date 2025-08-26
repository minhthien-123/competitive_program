#include <bits/stdc++.h>
#define task "reform"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 100000;
const int inf = 1e18;
const int mod = 1000000007;
const int inv = (mod + 1) / 2;

int n, m;
std::vector<int> adj[maxn + 7];
int num[maxn + 7], low[maxn + 7], timer;
int sz[maxn + 7];
int c, d, cnt;
int s;
int comp[maxn + 7];
int compSize[maxn + 7];

void tarjan(int u, int p)
{
    num[u] = low[u] = ++timer;
    sz[u] = 1;
    for (int v : adj[u])
    {
        if (v == p)
            continue;
        if (!num[v])
        {
            tarjan(v, u);
            sz[u] += sz[v];
            low[u] = std::min(low[u], low[v]);
            if (low[v] > num[u])
            {
                d++;
                s += sz[v] * (n - sz[v]);
            }
        }
        else
        {
            low[u] = std::min(low[u], num[v]);
        }
    }
}

signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    if (std::fopen(task ".inp", "r"))
    {
        std::freopen(task ".inp", "r", stdin);
        std::freopen(task ".out", "w", stdout);
    }

    std::cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        std::cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    for (int u = 1; u <= n; u++)
    {
        if (!num[u])
        {
            cnt++;
            tarjan(u, u);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        comp[i] = 0;
    }
    c = 0;
    for (int u = 1; u <= n; u++)
    {
        if (!comp[u])
        {
            c++;
            std::queue<int> q;
            q.push(u);
            comp[u] = c;
            while (!q.empty())
            {
                int x = q.front();
                q.pop();
                compSize[c]++;
                for (int v : adj[x])
                {
                    if (!comp[v])
                    {
                        comp[v] = c;
                        q.push(v);
                    }
                }
            }
        }
    }

    if (cnt > 2)
    {
        std::cout << 0 << "\n";
        return 0;
    }

    if (cnt == 2)
    {
        std::cout << (m - d) * (compSize[1] * compSize[2]);
    }
    else
    {
        int ans = s - d;
        ans += (m - d) * (n * (n - 1) / 2 - m);
        std::cout << ans;
    }

    return 0;
}
