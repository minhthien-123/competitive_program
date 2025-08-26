#include <bits/stdc++.h>
#define task "wires"
#define ll long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

int par[maxn + 7], sz[maxn + 7];

struct Edge
{
    int u, v;
    ll w;
    bool operator<(const Edge o)
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

int n, m;
ll ans;
std::vector<Edge> edges;
ii a[maxn + 7];

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

    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i].fi >> a[i].se;
    }

    for (int i = 1; i <= n; i++)
    {
        init(i);
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            ll dx = llabs(a[i].fi - a[j].fi);
            ll dy = llabs(a[i].se - a[j].se);
            edges.pb({i, j, dx + dy - std::__gcd(dx, dy)});
        }
    }

    std::sort(edges.begin(), edges.end());

    std::vector<ii> res;
    for (auto e : edges)
    {
        if (join(e.u, e.v))
        {
            ans += e.w;
            res.pb({e.u, e.v});
        }
    }

    std::cout << ans << "\n";
    for (auto i : res)
    {
        std::cout << i.fi << " " << i.se << "\n";
    }

    return 0;
}
