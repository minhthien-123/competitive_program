#include <bits/stdc++.h>
#define task "mst1"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;

int par[maxn + 7], sz[maxn + 7];

struct Edge
{
    int u, v, w;
    bool operator <(const Edge o)
    {
        return w < o.w;
    }
};

void init(int v)
{
    par[v] = v;
    sz[v] = 1;
}

int acs(int v)
{
    if (v == par[v])
    {
        return v;
    }
    int p = acs(par[v]);
    par[v] = p;
    return p;
}

bool join(int a, int b)
{
    a = acs(a);
    b = acs(b);
    if (a == b)
    {
        return false;
    }
    if (sz[a] < sz[b])
    {
        std::swap(a, b);
    }
    par[b] = a;
    sz[a] += sz[b];
    return true;
}

int n, m, ans;
std::vector<Edge> edges;

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> n >> m;
    while (m--)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        edges.pb({u, v, w});
    }

    for (int i = 1; i <= n; i++)
    {
        init(i);
    }

    std::sort(edges.begin(), edges.end());

    for (auto e : edges)
    {
        if (join(e.u, e.v))
        {
            ans += e.w;
        }
    }

    std::cout << ans;

    return 0;
}
