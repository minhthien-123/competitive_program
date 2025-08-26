#include <bits/stdc++.h>
#define task "drawer"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 3e5;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;

int n, l;
int sz[maxn + 7], par[maxn + 7];
int a[maxn + 7];

void init(int v)
{
    par[v] = v;
    sz[v] = 1;
    a[v] = 1;
}

int find(int v)
{
    if (v == par[v])
    {
        return v;
    }
    int p = find(par[v]);
    par[v] = p;
    return p;
}

bool join(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        if (sz[a] < sz[b])
        {
            std::swap(a, b);
        }
        par[b] = a;
        sz[a] += sz[b];
        return true;
    }
    return false;
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

    std::cin >> n >> l;

    for (int i = 1; i <= l; i++)
    {
        init(i);
    }

    while (n--)
    {
        int u, v;
        std::cin >> u >> v;

        if (find(u) != find(v))
        {
            int s = a[find(u)] + a[find(v)];
            join(u, v);
            a[find(u)] = s;
        }

        if (a[find(u)])
        {
            a[find(u)]--;
            std::cout << "LADICA\n";
        }
        else
        {
            std::cout << "SMECE\n";
        }
    }

    return 0;
}
