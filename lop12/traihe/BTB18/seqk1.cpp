#include <bits/stdc++.h>
#define task "seqk1"
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

const int maxn = 120;
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
int n, K, t;
int ans[maxn + 7];
int cnt;
std::vector<std::string> s1;
int c[120][120];

void init()
{
    for (int i = 0; i <= 120; i++)
    {
        c[i][0] = 1;
        for (int k = 1; k <= i; k++)
        {
            c[i][k] = c[i - 1][k - 1] + c[i - 1][k];
        }
    }
}

void Try(int i)
{
    for (int j = 0; j <= 1; j++)
    {
        ans[i] = j;
        if (i == n)
        {
            bool zero = true;
            int dem = 0;
            for (int i = 1; i <= n; i++)
            {
                if (ans[i] == 1)
                {
                    if (zero)
                    {
                        dem++;
                    }
                    zero = false;
                }
                else
                {
                    zero = true;
                }
            }
            if (dem == K)
            {
                std::string s;
                for (int k = 1; k <= n; k++)
                {
                    if (ans[k])
                    {
                        s += "1";
                    }
                    else
                    {
                        s += "0";
                    }
                }
                s1.pb(s);
            }
        }
        else
        {
            Try(i + 1);
        }
    }
}

void sub1()
{
    Try(1);

    std::cout << s1.size() << "\n";
    if (t >= 1 && t <= s1.size())
    {
        std::cout << s1[t - 1];
    }
}

void sub2()
{
    std::cout << c[n][2 * K - 1] + c[n][2 * K] << "\n";
}

void solve()
{
    std::cin >> n >> K >> t;

    init();

    if (n <= 20)
    {
        sub1();
    }
    else
    {
        sub2();
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
    // std::cin >> tt;
    while (tt--)
    {
        solve();
    }

    return 0;
}