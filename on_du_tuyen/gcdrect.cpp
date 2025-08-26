#include <bits/stdc++.h>
#define task "gcdrect"
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

int m, n;
int pre1[maxn + 7], pre2[maxn + 7];
int suf1[maxn + 7], suf2[maxn + 7];
int f[maxn + 7][maxn + 7];
int a[maxn + 7][maxn + 7];

bool check(int mid)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if ((j - 1) % mid == 0)
            {
                pre1[j] = a[i][j];
            }
            else
            {
                pre1[j] = std::__gcd(pre1[j - 1], a[i][j]);
            }
        }

        for (int j = m; j >= 1; j--)
        {
            if (j % mid == 0)
            {
                suf1[j] = a[i][j];
            }
            else
            {
                suf1[j] = std::__gcd(suf1[j + 1], a[i][j]);
            }
        }

        for (int j = 1; j + mid - 1 <= m; j++)
        {
            f[i][j] = std::__gcd(suf1[j], pre1[j + mid - 1]);
        }
    }

    for (int j = 1; j + mid - 1 <= m; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            if ((i - 1) % mid == 0)
            {
                pre2[i] = f[i][j];
            }
            else
            {
                pre2[i] = std::__gcd(pre2[i - 1], f[i][j]);
            }
        }

        for (int i = n; i >= 1; i--)
        {
            if (i % mid == 0)
            {
                suf2[i] = f[i][j];
            }
            else
            {
                suf2[i] = std::__gcd(suf2[i + 1], f[i][j]);
            }
        }

        for (int i = 1; i + mid - 1 <= n; i++)
        {
            if (std::__gcd(suf2[i], pre2[i + mid - 1]) > 1)
            {
                return true;
            }
        }
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

    int q;
    std::cin >> q;
    while (q--)
    {
        std::cin >> m >> n;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                std::cin >> a[i][j];
            }
        }

        int l = 1, r = std::min(m, n), ans = -1;

        while (l <= r)
        {
            int mid = (l + r) / 2;

            if (check(mid))
            {
                ans = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }

        std::cout << ans << "\n";
    }

    return 0;
}
