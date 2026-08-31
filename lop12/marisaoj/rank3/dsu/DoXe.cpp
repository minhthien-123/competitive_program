#include <bits/stdc++.h>
#define task "DoXe"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5 + 7;

int n, m;
int a[maxn], par[maxn];

void make_set()
{
    for (int v = 1; v <= n; v++)
    {
        par[v] = v;
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

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);
    if (std::fopen(task ".inp", "r"))
    {
        std::freopen(task ".inp", "r", stdin);
        std::freopen(task ".out", "w", stdout);
    }

    std::cin >> n;

    make_set();

    std::cout << "  ";
    for (int j = 1; j <= n; j++)
    {
        std::cout << par[j] << " ";
    }
    std::cout << "\n";

    for (int i = 1; i <= n; i++)
    {
        int v;
        std::cin >> v;
        std::cout << v << " ";
        a[i] = find_set(par[v]);
        int k = (par[v] + 1) % n;
        if (k == 0)
        {
            k = n;
        }
        // std::cout << k << " " << find_set(k) << "\n";
        if (par[v] != v)
        {
            par[find_set(v)] = par[k];
        }
        par[v] = par[k];
        for (int j = 1; j <= n; j++)
        {
                std::cout << par[j] << " ";
        }
        std::cout << "\n";
    }

    std::cout << "  ";
    for (int i = 1; i <= n; i++)
    {
        std::cout << a[i] << " ";
    }
    return 0;
}
