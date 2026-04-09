#include <bits/stdc++.h>
#define task ""
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

const int maxn = 1e5 + 5;
const ll inf = 1e18;
const int mod = 1e9 + 7;
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
int n;
ll a[maxn];
std::string s;
pll st[4 * maxn];
bool lazy[4 * maxn];

void fix(int id)
{
    if (lazy[id])
    {
        std::swap(st[2 * id].fi, st[2 * id].se);
        lazy[2 * id] = !lazy[2 * id];
        std::swap(st[2 * id + 1].fi, st[2 * id + 1].se);
        lazy[2 * id + 1] = !lazy[2 * id + 1];
        lazy[id] = false;
    }
}

void build(int id, int l, int r)
{
    lazy[id] = false;
    if (l == r)
    {
        if (s[l - 1] == '0')
        {
            st[id].fi = a[l];
            st[id].se = 0;
        }
        else
        {
            st[id].fi = 0;
            st[id].se = a[l];
        }
        return;
    }
    int mid = (l + r) / 2;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
    st[id].fi = st[2 * id].fi ^ st[2 * id + 1].fi;
    st[id].se = st[2 * id].se ^ st[2 * id + 1].se;
}

void update(int id, int l, int r, int u, int v)
{
    if (l > v || r < u)
    {
        return;
    }
    if (l >= u && r <= v)
    {
        std::swap(st[id].fi, st[id].se);
        lazy[id] = !lazy[id];
        return;
    }
    fix(id);
    int mid = (l + r) / 2;
    update(2 * id, l, mid, u, v);
    update(2 * id + 1, mid + 1, r, u, v);
    st[id].fi = st[2 * id].fi ^ st[2 * id + 1].fi;
    st[id].se = st[2 * id].se ^ st[2 * id + 1].se;
}

void solve()
{
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }
    std::cin >> s;
    build(1, 1, n);
    int q;
    std::cin >> q;
    while (q--)
    {
        int type;
        std::cin >> type;
        if (type == 1)
        {
            int l, r;
            std::cin >> l >> r;
            update(1, 1, n, l, r);
        }
        else
        {
            int g;
            std::cin >> g;
            if (g == 0)
            {
                std::cout << st[1].fi << " ";
            }
            else
            {
                std::cout << st[1].se << " ";
            }
        }
    }
    std::cout << "\n";
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

    int t;
    std::cin >> t;
    while (t--)
    {
        solve();
    }

    std::cerr << "\nTime elapsed: " << TIME << " s.\n";

    return 0;
}