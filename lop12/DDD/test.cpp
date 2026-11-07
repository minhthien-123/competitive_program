#include <bits/stdc++.h>
#define task "test"
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

const int maxn = 2e5 + 7;
const int inf = 1e9;

int n, m;
vi adj[maxn];
int st[4 * maxn], lazy[4 * maxn];

void build(int id, int l, int r)
{
    lazy[id] = 0;
    if (l == r)
    {
        st[id] = -l;
        return;
    }
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    st[id] = std::max(st[id << 1], st[id << 1 | 1]);
}

void push(int id)
{
    if (lazy[id] != 0)
    {
        int t = lazy[id];
        st[id << 1] += t;
        lazy[id << 1] += t;
        st[id << 1 | 1] += t;
        lazy[id << 1 | 1] += t;
        lazy[id] = 0;
    }
}

void update(int id, int l, int r, int u, int v, int val)
{
    if (v < l || r < u)
    {
        return;
    }
    if (u <= l && r <= v)
    {
        st[id] += val;
        lazy[id] += val;
        return;
    }
    push(id);
    int mid = (l + r) >> 1;
    update(id << 1, l, mid, u, v, val);
    update(id << 1 | 1, mid + 1, r, u, v, val);
    st[id] = std::max(st[id << 1], st[id << 1 | 1]);
}

int get(int id, int l, int r, int u, int v)
{
    if (v < l || r < u)
    {
        return -inf;
    }
    if (u <= l && r <= v)
    {
        return st[id];
    }
    push(id);
    int mid = (l + r) >> 1;
    return std::max(get(id << 1, l, mid, u, v), get(id << 1 | 1, mid + 1, r, u, v));
}

void solve()
{
    if (!(std::cin >> n >> m))
    {
        return;
    }

    for (int i = 1; i <= m; i++)
    {
        adj[i].clear();
    }

    for (int i = 1; i <= n; i++)
    {
        int l, r;
        std::cin >> l >> r;
        adj[r].pb(l);
    }

    build(1, 0, m);

    int max_unmatched = 0;

    for (int r = m; r >= 1; r--)
    {
        for (int l : adj[r])
        {
            update(1, 0, m, l, m, 1);
        }
        max_unmatched = std::max(max_unmatched, get(1, 0, m, 0, r - 1) + r - m - 1);
    }

    std::cout << n - max_unmatched << "\n";
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
