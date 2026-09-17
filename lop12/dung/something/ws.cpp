#include <bits/stdc++.h>
#define task "ws"
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

const int maxn = 1e6;
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

std::vector<int> adj[maxn + 7];
int k;
std::string s;
int cnt[maxn + 7];
bool is_prime[maxn + 7];

int power(int n, int p)
{
    int res = 0;
    for (int i = p; i <= n; i *= p)
    {
        res += n / i;
    }
    return res;
}

int power_mod(int x, int y, int m)
{
    int res = 1;
    x %= m;
    while (y > 0)
    {
        if (y & 1)
            res = (int)((__int128)res * x % m);
        x = (int)((__int128)x * x % m);
        y >>= 1;
    }
    return res;
}

void solve()
{
    std::cin >> k >> s;
    int n = s.size();
    s = " " + s;

    for (int i = 1; i <= n; i++)
    {
        cnt[s[i] - 'a']++;
        is_prime[i] = true;
    }

    is_prime[1] = false;

    std::vector<int> primes;
    for (int p = 2; p <= n; p++)
    {
        if (is_prime[p])
        {
            primes.push_back(p);
            for (int i = 2 * p; i <= n; i += p)
            {
                is_prime[i] = false;
            }
        }
    }

    int ans = 1 % k;
    for (int p : primes)
    {
        int pw = power(n, p);
        for (int i = 0; i < 26; i++)
        {
            if (cnt[i] > 1)
            {
                pw -= power(cnt[i], p);
            }
        }
        if (pw > 0)
        {
            ans = (int)((__int128)ans * power_mod(p, pw, k) % k);
        }
    }

    std::cout << ans << "\n";
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