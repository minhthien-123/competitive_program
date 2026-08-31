#include <bits/stdc++.h>
#define task ""
#define _Thiendeptrai_ signed main()
#define ll long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 5e3;
const ll inf = 1e18;
const int mod = 998244353;
const int inv = (mod + 1) / 2;
const int lg = 20;

ll add(ll x, ll y)
{
    return (x + y + 2 * mod) % mod;
}
ll sub(ll x, ll y)
{
    return (x - y + 2 * mod) % mod;
}
ll mul(ll x, ll y)
{
    return (x * y) % mod;
}

std::vector<int> adj[maxn + 7];
int n, k;
int dp[maxn + 7];

_Thiendeptrai_
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    if (std::fopen(task ".inp", "r"))
    {
        std::freopen(task ".inp", "r", stdin);
        std::freopen(task ".out", "w", stdout);
    }

    std::cin >> n >> k;

    dp[0] = 1;

    while (n--)
    {
        char c;
        int x;

        std::cin >> c >> x;
        if (c == '+')
        {
            for (int i = k; i >= x; i--)
            {
                dp[i] = add(dp[i], dp[i - x]);
            }
        }
        else
        {
            for (int i = x; i <= k; i++)
            {
                dp[i] = sub(dp[i], dp[i - x]);
            }
        }

        std::cout << dp[k] << "\n";
    }

    return 0;
}
