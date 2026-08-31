#include <bits/stdc++.h>
#define task ""
#define int long long
#define __Thien_dep_trai__ signed main()
#define ll long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define pll std::pair<ll, ll>
#define vi std::vector<int>
#define vii std::vector<ii>
#define fi first
#define se second
#define pb push_back
#define ins insert
#define sz(x) ((int)(x).size())
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define bit_set(x, pos) ((x) |= (1ULL << (pos)))
#define bit_clear(x, pos) ((x) &= ~(1ULL << (pos)))
#define all(x) x.begin(), x.end()

const int maxn = 1e6 + 7;
const ll INF = 1e18;
const int inf = 1e9;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;
const int lg = 20;
const int dx[] = {0, 1, 0, -1, -1, -1, 1, 1};
const int dy[] = {1, 0, -1, 0, -1, 1, -1, 1};

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
    return (x % mod * (y % mod)) % mod;
}
ll power(ll x, ll y)
{
    if (y == 0)
    {
        return 1;
    }
    ll tmp = power(x, y / 2);
    if (y % 2 == 0)
    {
        return (tmp * tmp) % mod;
    }
    else
    {
        return tmp * tmp % mod * x % mod;
    }
}

std::vector<int> adj[maxn + 7];

int dp[2][maxn];

bool is_match(char open, char close)
{
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

void solve()
{
    std::string s;
    std::cin >> s;

    int n = sz(s);
    if (n == 0)
    {
        std::cout << 0 << "\n";
        return;
    }

    for (int j = 0; j < n; j++)
    {
        dp[0][j] = dp[1][j] = 0;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        int cur = i & 1;
        int nxt = (i + 1) & 1;

        for (int j = i; j < n; j++)
        {
            if (i == j)
            {
                dp[cur][j] = 0;
            }
            else if (is_match(s[i], s[j]))
            {
                dp[cur][j] = dp[nxt][j - 1] + 1;
            }
            else
            {
                dp[cur][j] = std::max(dp[nxt][j], dp[cur][j - 1]);
            }
        }
    }

    std::cout << dp[0][n - 1] << "\n";
}

__Thien_dep_trai__
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    if (std::fopen(task ".inp", "r"))
    {
        std::freopen(task ".inp", "r", stdin);
        std::freopen(task ".out", "w", stdout);
    }

    int tt = 1;
    // std::cin >> tt;
    while (tt--)
    {
        solve();
    }

    std::cerr << "\nTime elapsed: " << TIME << " s.\n";

    return 0;
}