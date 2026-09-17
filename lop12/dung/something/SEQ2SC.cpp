#include <bits/stdc++.h>
#define task "SEQ2SC"
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

const int maxn = 1e3;
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
int m, n;
int a[maxn + 7], b[maxn + 7];
int prea[maxn + 7], preb[maxn + 7];

void solve()
{
    std::cin >> m >> n;
    for (int i = 1; i <= m; i++)
    {
        std::cin >> a[i];
        prea[i] = prea[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        std::cin >> b[i];
        preb[i] = preb[i - 1] + b[i];
    }

    std::vector<int> suma, sumb;
    for (int i = 1; i <= m; i++)
    {
        for (int j = i; j <= m; j++)
        {
            suma.pb(prea[j] - prea[i - 1]);
        }
    }
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            sumb.pb(preb[j] - preb[i - 1]);
        }
    }

    std::sort(all(sumb));

    int S = 0, E = 0, G = 0;
    for (auto x : suma)
    {
        auto it1 = std::lower_bound(all(sumb), x);
        auto it2 = std::upper_bound(all(sumb), x);

        G += (it1 - sumb.begin());
        E += (it2 - it1);
        S += (sumb.end() - it2);
    }

    std::cout << S << " " << E << " " << G;
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