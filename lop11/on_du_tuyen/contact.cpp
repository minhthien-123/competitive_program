#include <bits/stdc++.h>
#define task "contact"
#define int long long
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

int up[25][maxn], n, m, Pow[25];

bool getbit(int x, int kk)
{
    bool tt = x & (1 << (kk - 1));
    return tt;
}

int acs(int u, int k)
{
    if (up[k][u] == u)
    {
        return u;
    }
    else
    {
        return acs(up[k][u], k);
    }
}

void join(int x, int y, int k)
{
    if (x < y)
    {
        up[k][y] = x;
    }
    else
    {
        up[k][x] = y;
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
    Pow[0] = 1;
    for (int i = 1; i <= 20; i++)
    {
        Pow[i] = Pow[i - 1] * 2;
    }
    for (int i = 1; i <= 20; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            up[i][j] = j;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int p, q, l;
        std::cin >> p >> q >> l;
        for (int k = 20; k >= 1; k--)
        {
            if (getbit(l, k))
            {
                int u = acs(up[k][q], k);
                int v = acs(up[k][p], k);
                if (u != v)
                {
                    join(u, v, k);
                }
                q = q + Pow[k - 1];
                p = p + Pow[k - 1];
            }
        }
    }
    for (int i = 20; i >= 2; i--)
    {
        for (int j = 1; j <= n; j++)
        {
            int u = acs(up[i][j], i);
            if (u != j)
            {
                u = acs(u, i - 1);
                int v = acs(j, i - 1);
                if (u != v)
                {
                    join(u, v, i - 1);
                }
                int p = acs(j + Pow[i - 2], i - 1);
                int q = acs(u + Pow[i - 2], i - 1);
                if (p != q)
                {
                    join(p, q, i - 1);
                }
            }
        }
    }
    int d = 0;
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        if (up[1][i] == i)
        {
            d++;
        }
    }
    for (int i = 1; i <= d; i++)
    {
        ans = ans * 2;
        ans %= mod;
    }
    std::cout << ans;

    return 0;
}
