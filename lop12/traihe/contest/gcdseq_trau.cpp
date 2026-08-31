#include <bits/stdc++.h>
#define task "gcdseq"
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

const int maxn = 1e5;
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
int n, q, k;
int a[maxn + 7];
int st[25][maxn + 7];

int get(int l, int r)
{
    int j = std::__lg(r - l + 1);
    int res = std::__gcd(st[l][j], st[r - (1 << j) + 1][j]);
    return res;
}

void sub1(int l, int r)
{
    int ans = 0;
    for (int i = l; i <= r; i++)
    {
        for (int j = i; j <= r; j++)
        {
            int gcd = a[i];
            for (int x = i; x <= j; x++)
            {
                gcd = std::__gcd(gcd, a[x]);
            }
            // std::cout << i << " " << j << " " << gcd << "\n";
            if (gcd <= k)
            {
                ans++;
            }
        }
    }

    std::cout << ans << "\n";
}

void sub2(int l, int r)
{
    int ans = 0;
    for (int i = l; i <= r; i++)
    {
        for (int j = i; j <= r; j++)
        {
            int gcd = get(i, j);
            if (gcd <= k)
            {
                ans++;
            }
        }
    }
    std::cout << ans << "\n";
}

void solve()
{
    std::cin >> n >> q >> k;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }

    /*for (int i = 1; i <= n; i++)
    {
        st[i][0] = a[i];
    }
    for (int j = 1; (1 << j) <= n; j++)
    {
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
        {
            st[i][j] = std::__gcd(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }*/

    while (q--)
    {
        int l, r;
        std::cin >> l >> r;

        sub1(l, r);
        // std::cout << get(l, r) << "\n";
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
        std::freopen(task ".ans", "w", stdout);
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