#include <bits/stdc++.h>
#define task "weather"
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

std::string s;
int dp[maxn + 7];

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

    std::cin >> s;
    int n = s.size();
    s = " " + s;

    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = (dp[i] + dp[i - 1]) % mod;

        if ((s[i - 1] == 'N' && s[i] == 'W') || (s[i - 1] == 'W' && s[i] == 'S') || (s[i - 1] == 'S' && s[i] == 'E') || (s[i - 1] == 'E' && s[i] == 'N'))
        {
            dp[i] = (dp[i] + dp[i - 2]) % mod;
        }
    }

    std::cout << dp[n] << "\n";

    return 0;
}
