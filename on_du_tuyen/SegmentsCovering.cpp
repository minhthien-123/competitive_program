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

const int maxn = 2e5;
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

struct sc
{
    int l, r;
    ll p, q;
} a[maxn + 7];

std::vector<int> adj[maxn + 7];
int n, m;
ll f[maxn + 7], g[maxn + 7], d[maxn + 7];

bool cmp(sc x, sc y)
{
    return x.r < y.r;
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

ll xs(ll p, ll q)
{
    return mul(p % mod + mod, power(q, mod - 2));
}

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

    std::cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        d[i] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i].l >> a[i].r >> a[i].p >> a[i].q;
        d[a[i].r] = mul(d[a[i].r], xs(a[i].q - a[i].p, a[i].q));
    }
    std::sort(a + 1, a + n + 1, cmp);

    f[0] = 1;
    g[0] = 1;

    for (int i = 1; i <= m; i++)
    {
        g[i] = mul(g[i - 1], d[i]);
        //std::cout << g[i] << " ";
    }

    for (int i = 1; i <= n; i++)
    {
        int r = a[i].r;
        int l = a[i].l;
        int p = a[i].p;
        int q = a[i].q;
        f[r] = add(f[r], mul(f[l - 1], mul(xs(g[r], g[l - 1]), mul(xs(p, q), power(xs(q - p, q), mod - 2)))));
    }

    //std::cout << "\n";
    /*for (int i = 1; i <= m; i++)
    {
        std::cout << f[i] << " ";
    }*/

    std::cout << f[m];

    return 0;
}
