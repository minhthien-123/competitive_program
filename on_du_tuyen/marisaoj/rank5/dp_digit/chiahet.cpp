#include <bits/stdc++.h>
#define task "chiahet"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 12;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

int t;
int a, b, d;
int n;
int digit[maxn + 7];
int dp[maxn + 1][2][200][200];

int f(int pos, int flag, int rem, int sum)
{
    if (pos == n)
    {
        return (rem % d == 0) && (sum % d == 0);
    }

    int &memo = dp[pos][flag][rem][sum];
    if (memo != -1 && flag)
    {
        return memo;
    }

    int lim = flag ? 9 : digit[pos];
    int res = 0;
    for (int i = 0; i <= lim; i++)
    {
        res += f(pos + 1, flag || (i < lim), (rem * 10 + i) % d, (sum + i) % d);
    }

    if (flag)
    {
        memo = res;
    }

    return res;
}

int g(int k)
{
    std::vector<int> tmp;
    while (k > 0)
    {
        tmp.pb(k % 10);
        k /= 10;
    }
    n = tmp.size();
    std::reverse(tmp.begin(), tmp.end());
    for (int i = 0; i < n; i++)
    {
        digit[i] = tmp[i];
    }
    memset(dp, -1, sizeof dp);
    return f(0, 0, 0, 0);
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
        std::cin >> a >> b >> d;
        std::cout << g(b) - g(a - 1) << "\n";
    }

    return 0;
}