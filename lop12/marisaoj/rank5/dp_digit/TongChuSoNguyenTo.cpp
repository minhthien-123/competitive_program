#include <bits/stdc++.h>
#define task "dpdigit"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 13;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

int s;
bool is_prime[100005];
int n;
int digit[maxn + 7];
int dp[maxn + 7][300];

int f(int pos, int sum, bool flag)
{
    if (pos == n)
    {
        return (is_prime[sum]) ? 1 : 0;
    }

    int &memo = dp[pos][sum];
    if (flag && memo != -1)
    {
        return memo;
    }

    int lim = flag ? 9 : digit[pos];
    int res = 0;
    for (int i = 0; i <= lim; i++)
    {
        res += f(pos + 1, sum + i, flag || (i < lim));
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
    return f(0, 0, 0);
}

void sieve()
{
    std::memset(is_prime, 1, sizeof is_prime);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i < 100000; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j < 100000; j += i)
            {
                is_prime[j] = false;
            }
        }
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

    sieve();

    std::cin >> s;
    int l = 1, r = 10000000000000LL;
    int ans = -1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (g(mid) >= s)
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    std::cout << ans;

    return 0;
}
