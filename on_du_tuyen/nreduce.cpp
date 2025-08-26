#include <bits/stdc++.h>
#define task "net"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e3;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

int par1[maxn + 7], sz1[maxn + 7];
int par2[maxn + 7], sz2[maxn + 7];

struct edge
{
    int u, v, w;
};

int acs1(int v)
{
    if (v == par1[v])
    {
        return v;
    }
    int p = acs1(par1[v]);
    par1[v] = p;
    return p;
}

bool join1(int a, int b)
{
    a = acs1(a);
    b = acs1(b);
    if (a == b)
        return false;
    if (sz1[a] < sz1[b])
        std::swap(a, b);
    par1[b] = a;
    sz1[a] += sz1[b];
    return true;
}

int acs2(int v)
{
    if (v == par2[v])
    {
        return v;
    }
    int p = acs2(par2[v]);
    par2[v] = p;
    return p;
}

bool join2(int a, int b)
{
    a = acs2(a);
    b = acs2(b);
    if (a == b)
        return false;
    if (sz2[a] < sz2[b])
        std::swap(a, b);
    par2[b] = a;
    sz2[a] += sz2[b];
    return true;
}

inline void init1(int v)
{
    par1[v] = v;
    sz1[v] = 1;
}

inline void init2(int v)
{
    par2[v] = v;
    sz2[v] = 1;
}

signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    if (std::fopen(task ".inp", "r"))
    {
        std::freopen(task ".inp", "r", stdin);
        std::freopen(task ".out", "w", stdout);
    }

    int n, m;
    std::cin >> n >> m;
    std::vector<edge> edges;
    edges.reserve(m);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        edges.pb({u, v, w});
    }

    for (int i = 1; i <= n; i++)
    {
        init1(i);
        init2(i);
    }

    std::vector<int> ans;
    for (int i = 0; i < m; i++)
    {
        auto e = edges[i];
        if (e.w == 3)
        {
            if (acs1(e.u) != acs1(e.v) || acs2(e.u) != acs2(e.v))
            {
                join1(e.u, e.v);
                join2(e.u, e.v);
            }
            else
            {
                ans.pb(i + 1);
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        auto e = edges[i];
        if (e.w == 1)
        {
            if (!join1(e.u, e.v))
            {
                ans.pb(i + 1);
            }
        }
        if (e.w == 2)
        {
            if (!join2(e.u, e.v))
            {
                ans.pb(i + 1);
            }
        }
    }

    for (int i = 2; i <= n; i++)
    {
        if (acs1(i) != acs1(1) || acs2(i) != acs2(1))
        {
            std::cout << -1;
            return 0;
        }
    }

    std::cout << ans.size() << "\n";
    for (int x : ans)
    {
        std::cout << x << "\n";
    }

    return 0;
}
