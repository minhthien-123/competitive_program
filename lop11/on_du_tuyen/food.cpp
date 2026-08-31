#include <bits/stdc++.h>
#define task "food"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e6;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

int m, n;
int a[maxn + 7];
int pre[maxn + 7], prf[maxn + 7];
int d[maxn + 7];
int f[maxn + 7], pos[maxn + 7];
int sum;

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

    std::cin >> m >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }

    for (int i = 0; i < m; i++)
    {
        f[i] = -1;
        pos[i] = -1;
        d[i] = 0;
    }

    pre[0] = 0;
    for (int i = 0; i <= n; i++)
    {
        if (i > 0)
        {
            pre[i] = (pre[i - 1] + (a[i] % m) + m) % m;
            prf[i] = prf[i - 1] + a[i];
        }
        d[pre[i]]++;
        if (f[pre[i]] == -1)
        {
            f[pre[i]] = i;
        }
        pos[pre[i]] = i;
    }

    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        if (d[i] > 1)
        {
            ans += d[i] * (d[i] - 1) / 2;
        }
    }

    int l = 1, r = 1;
    int res = 0;
    for (int i = 0; i < m; i++)
    {
        if (d[i] > 1)
        {
            int L = f[i] + 1;
            int R = pos[i];
            int len = R - L + 1;
            if (len > res || (len == res && prf[R] - prf[L - 1] > sum))
            {
                res = len;
                l = L;
                r = R;
                sum = prf[R] - prf[L - 1];
            }
        }
    }

    std::cout << ans << "\n";
    if (ans > 0)
    {
        std::cout << l << " " << r << "\n";
    }

    return 0;
}
