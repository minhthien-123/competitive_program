#include <bits/stdc++.h>
#define task "ioibin"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e4 + 7;

int p;
int par[maxn], sz[maxn];

void make_set()
{
    for (int v = 1; v <= maxn; v++)
    {
        par[v] = v;
        sz[v] = 1;
    }
}

int find_set(int v)
{
    if (v == par[v])
    {
        return v;
    }
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
        par[b] = a;
        sz[a] += sz[b];
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

    make_set();

    std::cin >> p;
    while (p--)
    {
        int x, y, type;
        std::cin >> x >> y >> type;
        if (type == 1)
        {
            union_sets(x, y);
        }
        else
        {
            std::cout << (find_set(x) == find_set(y)) << "\n";
        }
    }

    return 0;
}
