#include <bits/stdc++.h>
#define task "colquery"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;
const int inf  = 1e18;

int n, q;
int sz[maxn + 7], par[maxn + 7], a[maxn + 7];
std::unordered_map<int, int> c[maxn + 7];

void make_set()
{
    for (int v = 1; v <= n; v++)
    {
        par[v] = v;
        sz[v] = 1;
        c[v][a[v]] = 1;
    }
}

int find_set(int v)
{
    if (v == par[v]) return v;
    int p = find_set(par[v]);
    par[v] = p;
    return p;
}

void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        if (sz[a] < sz[b])
        {
            std::swap(a, b);
        }
        sz[a] += sz[b];
        par[b] = a;

        for (auto i : c[b])
        {
            c[a][i.fi] += i.se;
        }
        c[b].clear();
    }
}

int get(int v, int color)
{
    v = find_set(v);
    if (c[v].find(color) == c[v].end())
    {
        return 0;
    }
    else
    {
        return c[v][color];
    }
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }

    make_set();

    while (q--)
    {
        int type, u, v;
        std::cin >> type >> u >> v;
        if (type == 1)
        {
            union_sets(u, v);
        }
        else
        {
            std::cout << get(u, v) << '\n';
        }
    }

    return 0;
}
