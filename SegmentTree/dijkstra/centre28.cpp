#include <bits/stdc++.h>
#define task "centre28"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 2e5;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

int add(int x, int y)
{
    return (x + y) % mod;
}

struct edge
{
    int u, v, w;
};

int n, m;
int d1[maxn + 7], dn[maxn + 7];
int dp11[maxn + 7], dp1n[maxn + 7], dpnn[maxn + 7], dpn1[maxn + 7];
std::vector<edge> edges;
std::vector<ii> adj[maxn + 7], a;
std::vector<int> dag1[maxn + 7], dagn[maxn + 7];

void dijk(int s, int d[])
{
    for (int i = 1; i <= n; i++)
    {
        d[i] = inf;
    }
    d[s] = 0;
    std::priority_queue<ii, std::vector<ii>, std::greater<>> pq;
    pq.push({d[s], s});

    while (!pq.empty())
    {
        auto tmp = pq.top();
        pq.pop();
        int du = tmp.fi;
        int u = tmp.se;
        if (du != d[u])
        {
            continue;
        }

        for (auto e : adj[u])
        {
            int v = e.fi;
            int w = e.se;
            if (d[u] + w < d[v])
            {
                d[v] = d[u] + w;
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
        int u, v, w;
        std::cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
        edges.pb({u, v, w});
    }

    dijk(1, d1);
    dijk(n, dn);

    for (auto e : edges)
    {
        int u = e.u;
        int v = e.v;
        int w = e.w;
        if (d1[u] + w == d1[v])
        {
            dag1[u].pb(v);
            dagn[v].pb(u);
        }
        if (d1[v] + w == d1[u])
        {
            dag1[v].pb(u);
            dagn[u].pb(v);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        a.pb({d1[i], i});
    }
    std::sort(a.begin(), a.end());

    dp11[1] = dp1n[1] = 1;
    for (ii i : a)
    {
        int u = i.se;
        for (int v : dag1[u])
        {
            dp11[v] = add(dp11[u], dp11[v]);
            dp1n[v] = add(dp1n[u], dp1n[v]);
        }
    }

    dpnn[n] = dpn1[n] = 1;
    for (int i = a.size() - 1; i >= 0; i--)
    {
        int u = a[i].se;
        for (int v : dagn[u])
        {
            dpnn[v] = add(dpnn[u], dpnn[v]);
            dpn1[v] = add(dpn1[u], dpn1[v]);
        }
    }

    int res1 = dp11[n];
    int res2 = dp1n[n];
    std::vector<int> ans;
    for (int i = 2; i < a.size(); i++)
    {
        int ans1 = dp11[i] * dpn1[i] % mod;
        int ans2 = dp1n[i] * dpnn[i] % mod;
        if (ans1 != res1 && ans2 != res2)
        {
            ans.pb(i);
        }
    }

    std::cout << ans.size() << "\n";
    for (int i : ans)
    {
        std::cout << i << "\n";
    }

    return 0;
}