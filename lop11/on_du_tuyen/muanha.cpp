#include <bits/stdc++.h>
#define task "muanha"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;

int n, k;
int a[maxn + 7];
bool prime[maxn + 7];
int sum = 0;
int pre[maxn + 7];
bool dp[maxn + 7];

void sieve()
{
    memset(prime, true, sizeof prime);
    prime[0] = prime[1] = 1;
    for (int i = 2; i * i <= maxn; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= maxn; j += i)
            {
                prime[j] = false;
            }
        }
    }
}

int solve(int pos)
{
    memset(dp, 0, sizeof dp);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (i == pos)
        {
            continue;
        }
        for (int s = sum; s >= a[i]; s--)
        {
            if (dp[s - a[i]])
            {
                dp[s] = 1;
            }
        }
    }

    int cnt = 0;
    for (int i = 2; i <= sum; i++)
    {
        if (dp[i] && prime[i])
        {
            cnt++;
        }
    }

    return cnt;
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
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        sum += a[i];
    }

    sieve();

    if (k == 0)
    {
        std::cout << solve(-1);
    }
    else
    {
        int ans = inf;
        for (int i = 1; i <= n; i++)
        {
            ans = std::min(ans, solve(i));
        }
        std::cout << ans;
    }

    return 0;
}