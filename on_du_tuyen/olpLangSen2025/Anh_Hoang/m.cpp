#include <bits/stdc++.h>
#define task "m"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 3e5;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

int n, m;
int d[maxn + 7], par[maxn + 7];
bool vis[maxn + 7];
std::queue<int> q;
std::vector<ii> adj[maxn + 7];

struct str
{
    int u, v, p, w;
} a[maxn + 7];

std::vector<str> v;

bool cmp(str a, str b)
{
    return a.p < b.p;
}

int find(int u)
{
    if (u == par[u])
    {
        return u;
    }
    return (par[u] = find(par[u]));
}

void join(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u != v)
    {
        par[u] = v;
    }
}

void dijkstra(int s)
{
    for (int i = 1; i <= n; i++)
    {
        d[i] = inf;
    }

    std::priority_queue<ii, std::vector<ii>, std::greater<ii>> pq;
    d[s] = 0;
    pq.push({d[s], s});
    while (!pq.empty())
    {
        int W = pq.top().fi;
        int u = pq.top().se;
        if (u == n)
        {
            return;
        }
        pq.pop();
        if (d[u] != W)
        {
            continue;
        }
        for (ii e : adj[u])
        {
            int v = e.fi;
            int w = e.se;
            if (d[v] > W + w)
            {
                d[v] = W + w;
                pq.push({d[v], v});
            }
        }
    }
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
        std::cin >> a[i].u >> a[i].v >> a[i].p >> a[i].w;
        v.pb(a[i]);
    }

    for (int i = 1; i <= n; i++)
    {
        par[i] = i;
    }

    std::sort(v.begin(), v.end(), cmp);

    int ans = -1;
    for (int i = 0; i < v.size(); i++)
    {
        join(v[i].u, v[i].v);
        adj[v[i].u].pb({v[i].v, v[i].w});
        adj[v[i].v].pb({v[i].u, v[i].w});
        if (find(1) == find(n))
        {
            for (int j = i + 1; j <= m; j++)
            {
                if (v[j].p != v[i].p)
                {
                    std::cout << v[i].p << " ";
                    break;
                }
                adj[v[j].u].pb({v[j].v, v[j].w});
                adj[v[j].v].pb({v[j].u, v[j].w});
            }
            break;
        }
    }

    dijkstra(1);
    std::cout << d[n] << "\n";

    return 0;
}
