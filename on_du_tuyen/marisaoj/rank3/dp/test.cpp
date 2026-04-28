#include <bits/stdc++.h>
#define task ""
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e3;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;

int n, k;
int dp[107][maxn + 7];
bool prime[2 * maxn + 7];
std::vector<int> primes;

void sieve()
{
    for (int i = 2; i * i <= 2 * maxn; i++)
    {
        if (!prime[i])
        {
            for (int j = i * i; j <= 2 * maxn; j += i)
            {
                prime[j] = true;
            }
        }
    }

    for (int i = 2; i <= 2 * k; i++)
    {
        if (!prime[i])
        {
            primes.pb(i);
        }
    }
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> n >> k;
    sieve();
    for (int i : primes)
    {
        std::cout << i << " ";
    }
    for (int j = 0; j <= k; j++)
    {
        dp[1][j] = 1;
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            for (int p : primes)
            {
                if (p >= j && p - j <= k)
                {
                    dp[i][j] = (dp[i][j] % mod + dp[i - 1][p - j] % mod) % mod;
                }
            }
        }
    }

    int ans = 0;
    for (int j = 0; j <= k; j++)
    {
        ans = (ans % mod + dp[n][j] % mod) % mod;
    }
    std::cout << ans;

    return 0;
}
