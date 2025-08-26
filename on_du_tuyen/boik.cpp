#include <bits/stdc++.h>
#define task "boik"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 10000;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

std::string k;
int d;
int dp[2][maxn + 7][107];

int f(int pos, bool flag, int sum)
{
    if (pos < 0)
    {
        return (sum % d == 0) ? 1 : 0;
    }
    int &memo = dp[flag][pos][sum];
    if (memo != -1)
    {
        return memo;
    }

    int lim = flag ? 9 : k[k.size() - pos - 1] - '0';
    memo = 0;
    for (int i = 0; i <= lim; i++)
    {
        memo += f(pos - 1, flag || (i < lim), (sum + i) % d);
        memo = (memo + mod) % mod;
    }

    return memo;
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

    std::cin >> k >> d;

    memset(dp, -1, sizeof dp);
    int ans = f(k.size() - 1, 0, 0) - 1;
    ans = (ans + mod) % mod;
    std::cout << ans << '\n';

    return 0;
}
