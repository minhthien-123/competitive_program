#include <bits/stdc++.h>
#define task "ioibin"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e4 + 7;

int n, m;
int par[maxn], sz[maxn];

void make_set(int v)
{
    par[v] = v;
    sz[v] = 1;
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

bool union_sets(int a, int b)
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
        return true;
    }
    return false;
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

    for (int i = 1; i <= n; i++)
    {
        make_set(i);
    }

    int ans = n;

    while (m--)
    {
        int x, y;
        std::cin >> x >> y;
        if (union_sets(x, y))
        {
            ans--;
        }
        std::cout << ans << "\n";
    }

    return 0;
}
