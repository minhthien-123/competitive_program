#include <bits/stdc++.h>
#define task "class"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e6;
const int inf = 1e18;
const int mod = 1000000007;
const int inv = (mod + 1) / 2;

int t;
int a[maxn + 7], x[maxn + 7], y[maxn + 7];
int p[maxn + 7], pre[maxn + 7];

int power(int x, int y)
{
    x %= mod;
    if (x < 0)
        x += mod;
    if (y == 0)
    {
        return 1;
    }
    int tmp = power(x, y / 2);
    if (y % 2 == 0)
    {
        return (tmp * tmp) % mod;
    }
    else
    {
        return (tmp * tmp % mod) * x % mod;
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

    std::cin >> t;
    while (t--)
    {
        int n, k, x1, y1, c, d, e1, e2, f;
        std::cin >> n >> k >> x1 >> y1 >> c >> d >> e1 >> e2 >> f;
        x[1] = x1;
        y[1] = y1;
        a[1] = (x1 + y1) % f;
        for (int i = 2; i <= n; i++)
        {
            x[i] = (c * x[i - 1] + d * y[i - 1] + e1) % f;
            y[i] = (d * x[i - 1] + c * y[i - 1] + e2) % f;
            a[i] = (x[i] + y[i]) % f;
        }

        for (int i = 1; i <= n; i++)
        {
            if (i == 1)
            {
                p[i] = k % mod;
            }
            else
            {
                int num = (power(i, k + 1) - (i % mod)) % mod;
                if (num < 0)
                {
                    num += mod;
                }
                int inv_den = power((i - 1) % mod, mod - 2);
                p[i] = (num * inv_den) % mod;
            }
        }

        pre[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            pre[i] = (pre[i - 1] + p[i]) % mod;
        }

        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            int tmp = ((a[i] * (n - i + 1)) % mod) % mod;
            ans = (ans + tmp * pre[i]) % mod;
        }

        std::cout << ans << "\n";
    }

    return 0;
}
