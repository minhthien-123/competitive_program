#include <bits/stdc++.h>
#define task "a"
#define int long long
#define int128 __int128_t
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

int n;
int a[maxn + 7];
int128 dp[maxn + 7];

void print(int128 x)
{
    if (x == 0)
    {
        std::cout << "0";
        return;
    }

    if (x < 0)
    {
        std::cout << "-";
        x = -x;
    }

    std::string s;
    while (x > 0)
    {
        int digit = (int)(x % 10);
        s.pb(char(digit + '0'));
        x /= 10;
    }
    std::reverse(s.begin(), s.end());
    std::cout << s;
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

    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }

    std::sort(a + 1, a + n + 1, std::greater<int>());

    int128 INF128 = (int128)inf * (int128)inf;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = INF128;
    }
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        int128 cost = 0;
        for (int j = i; j >= 1; j--)
        {
            cost = (int128)a[j] + cost * 2;

            int128 res = dp[j - 1] + cost;
            if (j > 1)
            {
                res += (int128)3600;
            }

            if (res < dp[i])
            {
                dp[i] = res;
            }
        }
    }

    print(dp[n]);

    return 0;
}
