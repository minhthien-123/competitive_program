#include <bits/stdc++.h>
#define task "maze"
#define __Thien_dep_trai__ signed main()
#define ll long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define pll std::pair<ll, ll>
#define vi std::vector<int>
#define vii std::vector<ii>
#define fi first
#define se second
#define pb push_back
#define ins insert
#define sz(x) ((int)(x).size())
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define bit_set(x, pos) ((x) |= (1ULL << (pos)))
#define bit_clear(x, pos) ((x) &= ~(1ULL << (pos)))
#define all(x) x.begin(), x.end()

const int maxn = 1e2;
const int inf = 1e9;
const int mod = 1e9 + 7;

int n, m;

struct DSU
{
    std::vector<int> par, sz;

    DSU() {}
    DSU(int n)
    {
        par.resize(n + 7);
        sz.resize(n + 7);

        for (int i = 0; i <= n + 1; i++)
        {
            par[i] = i;
            sz[i] = 1;
        }
    }

    int acs(int v)
    {
        return v == par[v] ? v : par[v] = acs(par[v]);
    }

    void join(int u, int v)
    {
        u = acs(u);
        v = acs(v);
        if (u != v)
        {
            if (sz[u] < sz[v])
            {
                std::swap(u, v);
            }
            par[v] = u;
            sz[u] += sz[v];
        }
    }
};

DSU dsu[16];

int calc(char c)
{
    if (c == 'P')
        return 0;
    if (c == 'C')
        return 1;
    if (c == 'Z')
        return 2;
    if (c == 'N')
        return 3;
    return -1;
}

int idx(int x, int y)
{
    return (x - 1) * m + y;
}

__Thien_dep_trai__
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
    for (int i = 1; i < 16; i++)
    {
        dsu[i] = DSU(n * m);
    }

    for (int i = 1; i <= n; i++)
    {
        std::string s;
        std::cin >> s;
        for (int j = 1; j < m; j++)
        {
            int u = idx(i, j);
            int v = idx(i, j + 1);
            int c = calc(s[j - 1]);
            for (int mask = 1; mask < 16; mask++)
            {
                if (mask & (1 << c))
                {
                    dsu[mask].join(u, v);
                }
            }
        }
    }
    for (int i = 1; i < n; i++)
    {
        std::string s;
        std::cin >> s;
        for (int j = 1; j <= m; j++)
        {
            int u = idx(i, j);
            int v = idx(i + 1, j);
            int c = calc(s[j - 1]);
            for (int mask = 1; mask < 16; mask++)
            {
                if (mask & (1 << c))
                {
                    dsu[mask].join(u, v);
                }
            }
        }
    }

    int q;
    std::cin >> q;
    while (q--)
    {
        int x, y, z, t;
        std::cin >> x >> y >> z >> t;
        int u = idx(x, y);
        int v = idx(z, t);

        int ans = 10;
        for (int mask = 1; mask < 16; mask++)
        {
            if (dsu[mask].acs(u) == dsu[mask].acs(v))
            {
                ans = std::min(ans, __builtin_popcount(mask));
            }
        }
        std::cout << ans << "\n";
    }

    std::cerr << "\nTime elapsed: " << TIME << " s.\n";

    return 0;
}