#include <bits/stdc++.h>
#define task "TwoSequenceQueries"
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

const int maxn = 200000;
const ll mod = 998244353;

ll addmod(ll x, ll y)
{
    x %= mod;
    if (x < 0)
        x += mod;
    y %= mod;
    if (y < 0)
        y += mod;
    ll z = x + y;
    if (z >= mod)
        z -= mod;
    return z;
}
ll submod(ll x, ll y)
{
    x %= mod;
    if (x < 0)
        x += mod;
    y %= mod;
    if (y < 0)
        y += mod;
    ll z = x - y;
    if (z < 0)
        z += mod;
    return z;
}
ll mulmod(ll x, ll y)
{
    x %= mod;
    if (x < 0)
        x += mod;
    y %= mod;
    if (y < 0)
        y += mod;
    return (x * y) % mod;
}

struct tree
{
    ll a, b, ab, x, y;
} st[4 * maxn + 7];

int n, q;
ll a[maxn + 7], b[maxn + 7];

void build(int id, int l, int r)
{
    st[id].a = st[id].b = st[id].ab = st[id].x = st[id].y = 0;
    if (l == r)
    {
        st[id].a = a[l] % mod;
        if (st[id].a < 0)
            st[id].a += mod;
        st[id].b = b[l] % mod;
        if (st[id].b < 0)
            st[id].b += mod;
        st[id].ab = mulmod(st[id].a, st[id].b);
        return;
    }
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    st[id].a = addmod(st[id << 1].a, st[id << 1 | 1].a);
    st[id].b = addmod(st[id << 1].b, st[id << 1 | 1].b);
    st[id].ab = addmod(st[id << 1].ab, st[id << 1 | 1].ab);
}

void apply(int id, int l, int r, ll x, ll y)
{
    if (x == 0 && y == 0)
        return;
    int len = r - l + 1;
    ll sa = st[id].a;
    ll sb = st[id].b;
    st[id].a = addmod(st[id].a, mulmod(len, x));
    st[id].b = addmod(st[id].b, mulmod(len, y));
    // new_ab = old_ab + x*sum_b + y*sum_a + len*x*y
    ll delta = addmod(mulmod(x, sb), addmod(mulmod(y, sa), mulmod(len, mulmod(x, y))));
    st[id].ab = addmod(st[id].ab, delta);
    st[id].x = addmod(st[id].x, x);
    st[id].y = addmod(st[id].y, y);
}

void push(int id, int l, int r)
{
    if (st[id].x == 0 && st[id].y == 0)
        return;
    int mid = (l + r) >> 1;
    apply(id << 1, l, mid, st[id].x, st[id].y);
    apply(id << 1 | 1, mid + 1, r, st[id].x, st[id].y);
    st[id].x = st[id].y = 0;
}

void update(int id, int l, int r, int u, int v, ll x, ll y)
{
    if (v < l || r < u)
        return;
    if (u <= l && r <= v)
    {
        apply(id, l, r, x % mod, y % mod);
        return;
    }
    push(id, l, r);
    int mid = (l + r) >> 1;
    update(id << 1, l, mid, u, v, x, y);
    update(id << 1 | 1, mid + 1, r, u, v, x, y);
    st[id].a = addmod(st[id << 1].a, st[id << 1 | 1].a);
    st[id].b = addmod(st[id << 1].b, st[id << 1 | 1].b);
    st[id].ab = addmod(st[id << 1].ab, st[id << 1 | 1].ab);
}

ll get(int id, int l, int r, int u, int v)
{
    if (v < l || r < u)
        return 0;
    if (u <= l && r <= v)
        return st[id].ab;
    push(id, l, r);
    int mid = (l + r) >> 1;
    ll g1 = get(id << 1, l, mid, u, v);
    ll g2 = get(id << 1 | 1, mid + 1, r, u, v);
    return addmod(g1, g2);
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

    std::cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        a[i] %= mod;
        if (a[i] < 0)
            a[i] += mod;
    }
    for (int i = 1; i <= n; i++)
    {
        std::cin >> b[i];
        b[i] %= mod;
        if (b[i] < 0)
            b[i] += mod;
    }

    build(1, 1, n);

    while (q--)
    {
        int type, l, r;
        ll x;
        std::cin >> type >> l >> r;
        if (type == 1)
        {
            std::cin >> x;
            x %= mod;
            if (x < 0)
                x += mod;
            update(1, 1, n, l, r, x, 0);
        }
        else if (type == 2)
        {
            std::cin >> x;
            x %= mod;
            if (x < 0)
                x += mod;
            update(1, 1, n, l, r, 0, x);
        }
        else
        {
            std::cout << get(1, 1, n, l, r) << '\n';
        }
    }

    std::cerr << "\nTime elapsed: " << TIME << " s.\n";

    return 0;
}
