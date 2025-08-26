#include <bits/stdc++.h>
#define task "carpet"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 3e2;
const int maxk = 2e4;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

struct query
{
    char ch;
    int a, b, c, d;
};

int m, n, k;
int a[maxn + 7][maxn + 7], f[maxn + 7][maxn + 7];
query q[maxk + 7];

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

    std::cin >> m >> n >> k;

    int tmp = 1;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            a[i][j] = tmp++;
        }
    }

    for (int i = 1; i <= k; i++)
    {
        std::cin >> q[i].ch >> q[i].a >> q[i].b >> q[i].c >> q[i].d;
    }

    for (int i = k; i >= 1; i--)
    {
        if (q[i].ch == 'H')
        {
            for (int j = q[i].a; j <= q[i].c; j++)
            {
                for (int l = q[i].b; l <= q[i].d; l++)
                {
                    f[j][l] = a[j][l];
                }
            }

            for (int j = q[i].a; j <= q[i].c; j++)
            {
                for (int l = q[i].b; l <= q[i].d; l++)
                {
                    a[j][l] = f[j][q[i].b + q[i].d - l];
                }
            }
        }
        else
        {
            for (int j = q[i].a; j <= q[i].c; j++)
            {
                for (int l = q[i].b; l <= q[i].d; l++)
                {
                    f[j][l] = a[j][l];
                }
            }

            for (int j = q[i].a; j <= q[i].c; j++)
            {
                for (int l = q[i].b; l <= q[i].d; l++)
                {
                    a[j][l] = f[q[i].a + q[i].c - j][l];
                }
            }
        }
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            std::cout << a[i][j] << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}
