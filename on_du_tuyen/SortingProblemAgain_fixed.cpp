#include <bits/stdc++.h>
#define task "SortingProblemAgain"
#define _Thien_dep_trai_ signed main()
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

const int maxn = 5e5;
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

struct tree
{
    ll mn, mx;
} st[4 * maxn + 7];

std::vector<int> adj[maxn + 7];
int t, n, q;
ll a[maxn + 7];
ll f[4 * maxn + 7];
ll b[maxn + 7];

tree merge(tree x, tree y)
{
    tree res;
    res.mn = std::min(x.mn, y.mn);
    res.mx = std::max(x.mx, y.mx);
    return res;
}

void build(int id, int l, int r)
{
    if (l == r)
    {
        st[id] = {a[l], a[l]};
        return;
    }

    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    st[id] = merge(st[id * 2], st[id * 2 + 1]);
}

void update(int id, int l, int r, int pos, ll val)
{
    if (pos < l || pos > r)
    {
        return;
    }
    if (l == r)
    {
        st[id] = {val, val};
        return;
    }

    int mid = (l + r) / 2;
    update(id * 2, l, mid, pos, val);
    update(id * 2 + 1, mid + 1, r, pos, val);
    st[id] = merge(st[id * 2], st[id * 2 + 1]);
}

tree get(int id, int l, int r, int u, int v)
{
    if (v < l || r < u)
    {
        return {inf, -inf};
    }
    if (u <= l && r <= v)
    {
        return st[id];
    }

    int mid = (l + r) / 2;
    tree get1 = get(id * 2, l, mid, u, v);
    tree get2 = get(id * 2 + 1, mid + 1, r, u, v);
    return merge(get1, get2);
}

int findR(int id, int l, int r, int u, int v, ll val)
{
    if (v < l || r < u)
    {
        return -1;
    }
    if (st[id].mx <= val)
    {
        return -1;
    }
    if (l == r)
    {
        return l;
    }
    int mid = (l + r) / 2;
    int res = findR(id * 2 + 1, mid + 1, r, u, v, val);
    if (res != -1)
    {
        return res;
    }
    return findR(id * 2, l, mid, u, v, val);
}

int findL(int id, int l, int r, int u, int v, ll val)
{
    if (v < l || r < u)
    {
        return -1;
    }
    if (st[id].mn >= val)
    {
        return -1;
    }
    if (l == r)
    {
        return l;
    }
    int mid = (l + r) / 2;
    int res = findL(id * 2, l, mid, u, v, val);
    if (res != -1)
    {
        return res;
    }
    return findL(id * 2 + 1, mid + 1, r, u, v, val);
}

void buildf(int id, int l, int r)
{
    if (l == r)
    {
        f[id] = b[l];
        return;
    }

    int mid = (l + r) / 2;
    buildf(id * 2, l, mid);
    buildf(id * 2 + 1, mid + 1, r);
    f[id] = std::min(f[id * 2], f[id * 2 + 1]);
}

void updatef(int id, int l, int r, int pos, ll val)
{
    if (pos < l || pos > r)
    {
        return;
    }
    if (l == r)
    {
        f[id] = val;
        return;
    }

    int mid = (l + r) / 2;
    updatef(id * 2, l, mid, pos, val);
    updatef(id * 2 + 1, mid + 1, r, pos, val);
    f[id] = std::min(f[id * 2], f[id * 2 + 1]);
}

ll getf(int id, int l, int r, int u, int v)
{
    if (v < l || r < u)
    {
        return inf;
    }
    if (u <= l && r <= v)
    {
        return f[id];
    }

    int mid = (l + r) / 2;
    ll get1 = getf(id * 2, l, mid, u, v);
    ll get2 = getf(id * 2 + 1, mid + 1, r, u, v);
    return std::min(get1, get2);
}

int findfL(int id, int l, int r, int u, int v)
{
    if (v < l || r < u)
    {
        return -1;
    }
    if (f[id] >= 0)
    {
        return -1;
    }
    if (l == r)
    {
        return l;
    }
    int mid = (l + r) / 2;
    int res = findfL(id * 2, l, mid, u, v);
    if (res != -1)
    {
        return res;
    }
    return findfL(id * 2 + 1, mid + 1, r, u, v);
}

int findfR(int id, int l, int r, int u, int v)
{
    if (v < l || r < u)
    {
        return -1;
    }
    if (f[id] >= 0)
    {
        return -1;
    }
    if (l == r)
    {
        return l;
    }
    int mid = (l + r) / 2;
    int res = findfR(id * 2 + 1, mid + 1, r, u, v);
    if (res != -1)
    {
        return res;
    }
    return findfR(id * 2, l, mid, u, v);
}

bool checkL(int mid)
{
    tree x = get(1, 1, n, 1, mid);
    tree y = get(1, 1, n, mid + 1, n);
    return x.mx <= y.mn;
}

bool checkR(int mid)
{
    tree x = get(1, 1, n, 1, mid);
    tree y = get(1, 1, n, mid + 1, n);
    return x.mx <= y.mn;
}

bool check(int l, int r)
{
    ll tmp = getf(1, 1, n, l, r);
    return tmp >= 0;
}

void solve()
{
    if (n == 1)
    {
        std::cout << -1 << " " << -1 << "\n";
        return;
    }

    if (getf(1, 1, n, 1, n) >= 0)
    {
        std::cout << -1 << " " << -1 << "\n";
        return;
    }

    int l = findfL(1, 1, n, 2, n);
    int r = findfR(1, 1, n, 2, n);

    if (l == -1 || r == -1)
    {
        std::cout << -1 << " " << -1 << "\n";
        return;
    }

    tree cur = get(1, 1, n, l - 1, r);
    ll mn = cur.mn;
    ll mx = cur.mx;

    int L = -1;
    if (l - 1 >= 1)
    {
        L = findR(1, 1, n, 1, l - 1, mn);
    }
    int l;
    if (L == -1)
    {
        l = 1;
    }
    else
    {
        l = L + 1;
    }

    int R = -1;
    if (r + 1 <= n)
    {
        R = findL(1, 1, n, r + 1, n, mx);
    }
    int r;
    if (R == -1)
    {
        r = n;
    }
    else
    {
        r = R - 1;
    }

    std::cout << l << " " << r << "\n";
}

_Thien_dep_trai_
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    if (std::fopen(task ".inp", "r"))
    {
        std::freopen(task ".inp", "r", stdin);
        std::freopen(task ".out", "w", stdout);
    }

    std::cin >> t;
    while (t--)
    {
        std::cin >> n;
        for (int i = 1; i <= n; i++)
        {
            std::cin >> a[i];
        }

        b[1] = inf;
        for (int i = 2; i <= n; i++)
        {
            b[i] = a[i] - a[i - 1];
        }

        build(1, 1, n);
        buildf(1, 1, n);

        std::cin >> q;

        solve();

        while (q--)
        {
            int pos;
            ll val;
            std::cin >> pos >> val;

            a[pos] = val;
            update(1, 1, n, pos, val);
            b[pos] = a[pos] - a[pos - 1];
            updatef(1, 1, n, pos, b[pos]);
            b[pos + 1] = a[pos + 1] - a[pos];
            updatef(1, 1, n, pos + 1, b[pos + 1]);

            solve();
        }
    }

    std::cerr << "\nTime elapsed: " << TIME << " s.\n";

    return 0;
}