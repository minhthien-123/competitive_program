#include <bits/stdc++.h>
#define task "bumeran"
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

const int maxn = 250;
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
    return (x * y) % mod;
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
int dp[maxn + 7][maxn + 7], nxt[maxn + 7][2];
int n;
std::string s;

int calc(int pos, int c)
{
    if (dp[pos][c] != -1)
    {
        return dp[pos][c];
    }

    int res = 0;
    if (c == 0)
    {
        res = 1;
    }

    int nxtf = nxt[pos][0];
    if (nxtf != -1)
    {
        res = add(res, calc(nxtf, c + 1));
    }

    if (c > 0)
    {
        int nxtr = nxt[pos][1];
        if (nxtr != -1)
        {
            res = add(res, calc(nxtr, c - 1));
        }
    }

    dp[pos][c] = res;
    return res;
}

void solve()
{
    std::cin >> s;
    n = sz(s);
    s = ' ' + s;

    for (int i = 0; i <= n; i++)
    {
        nxt[i][0] = -1;
        nxt[i][1] = -1;
        for (int j = i + 1; j <= n; j++)
        {
            if (nxt[i][0] == -1 && s[j] == 'F')
            {
                nxt[i][0] = j;
            }
            if (nxt[i][1] == -1 && s[j] == 'R')
            {
                nxt[i][1] = j;
            }
        }
    }

    memset(dp, -1, sizeof(dp));

    int pos = nxt[0][0];
    if (pos != -1)
    {
        std::cout << calc(pos, 1) << "\n";
    }
    else
    {
        std::cout << 0 << "\n";
    }
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
    //std::cin >> tt;
    while (tt--)
    {
        solve();
    }

    std::cerr << "\nTime elapsed: " << TIME << " s.\n";

    return 0;
}