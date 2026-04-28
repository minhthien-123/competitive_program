#include <bits/stdc++.h>
#define task "b2"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 3e5;
const int inf = 1e18;
const int mod = 1e9 + 9;
const int inv = (mod + 1) / 2;

int n, m;
int a[maxn + 7];
ii f[maxn + 7], pre[maxn + 7], lz[maxn + 7];
int st[4 * maxn + 7];

void build(int id, int l, int r)
{
    if (l == r)
    {
        st[id] = a[l];
        return;
    }

    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    st[id] = (st[id * 2] + st[id * 2 + 1]) % mod;
}

ii sum(ii u, ii v)
{
    u.fi = (u.fi + v.fi) % mod;
    u.se = (u.se + v.se) % mod;
    return u;
}

void Down(int id, int i)
{
    lz[id * 2] = sum(lz[id * 2], lz[id]);
    lz[id * 2 + 1].fi = (lz[id * 2 + 1].fi + lz[id].fi * f[i].fi + lz[id].se * f[i].se) % mod;
    lz[id * 2 + 1].se = (lz[id * 2 + 1].se + lz[id].fi * f[i + 1].fi + lz[id].se * f[i + 1].se) % mod;

    st[id * 2] = (st[id * 2] + pre[i].fi * lz[id].fi + pre[i].se * lz[id].se) % mod;
    st[id * 2 + 1] = (st[id] - st[id * 2] + mod) % mod;

    lz[id] = {0, 0};
}

void update(int id, int l, int r, int u, int v)
{
    if (u > r || l > v)
    {
        return;
    }

    if (u <= l && r <= v)
    {
        lz[id].fi = (lz[id].fi + f[l - u].se) % mod;
        lz[id].se = (lz[id].se + f[l - u + 1].se) % mod;
        st[id] = (st[id] + pre[r - u + 1].se - pre[l - u].se + mod) % mod;
        return;
    }

    int mid = (l + r) / 2;
    Down(id, mid - l + 1);
    update(id * 2, l, mid, u, v);
    update(id * 2 + 1, mid + 1, r, u, v);
    st[id] = (st[id * 2] + st[id * 2 + 1]) % mod;
}

int get(int id, int l, int r, int u, int v)
{
    if (u > r || l > v)
    {
        return 0;
    }

    if (u <= l && r <= v)
    {
        return st[id];
    }

    int mid = (l + r) / 2;
    Down(id, mid + 1 - l);
    return (get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v));
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    int q;
    std::cin >> n >> q;
    f[0] = {1, 0};
    f[1] = {0, 1};
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];

        if (i > 1)
        {
            f[i] = sum(f[i - 2], f[i - 1]);
        }
        pre[i] = sum(pre[i - 1], f[i]);
    }
    build(1, 1, n);

    for (int i = 1; i <= q; i++)
    {
        int type, l, r;
        std::cin >> type >> l >> r;

        if (type == 1)
        {
            update(1, 1, n, l, r);
        }
        else
        {
            int ans = get(1, 1, n, l, r);
            assert(ans >= 0);
            std::cout << ans << '\n';
        }
    }

    return 0;
}
