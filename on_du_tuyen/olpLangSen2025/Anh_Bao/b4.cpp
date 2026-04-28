#include <bits/stdc++.h>
#define task "b4"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;

struct b4
{
    int mx, sum;
} st[4 * maxn + 7];

int n, m;
int a[maxn + 7];

void build(int id, int l, int r)
{
    if (l == r)
    {
        st[id].mx = a[l];
        st[id].sum = a[l];
        return;
    }

    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    st[id].sum = st[id * 2].sum + st[id * 2 + 1].sum;
    st[id].mx  = std::max(st[id * 2].mx, st[id * 2 + 1].mx);
}

void update1(int id, int l, int r, int u, int v, int x)
{
    if (st[id].mx < x)
    {
        return;
    }

    if (v < l || r < u)
    {
        return;
    }
    if (l == r)
    {
        st[id].sum = st[id].mx = (st[id].mx % x);
        return;
    }

    int mid = (l + r) / 2;
    update1(id * 2, l, mid, u, v, x);
    update1(id * 2 + 1, mid + 1, r, u, v, x);
    st[id].sum = st[id * 2].sum + st[id * 2 + 1].sum;
    st[id].mx = std::max(st[id * 2].mx, st[id * 2 + 1].mx);
}

void update2(int id, int l, int r, int pos, int val)
{
    if (pos < l || pos > r)
    {
        return;
    }
    if (l == r)
    {
        st[id].mx  = val;
        st[id].sum = val;
        return;
    }

    int mid = (l + r) / 2;
    update2(id * 2, l, mid, pos, val);
    update2(id * 2 + 1, mid + 1, r, pos, val);
    st[id].sum = st[id * 2].sum + st[id * 2 + 1].sum;
    st[id].mx = std::max(st[id * 2].mx, st[id * 2 + 1].mx);
}

int get(int id, int l, int r, int u, int v)
{
    if (v < l || r < u)
    {
        return 0;
    }
    if (u <= l && r <= v)
    {
        return st[id].sum;
    }
    int mid = (l + r) / 2;
    return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }

    build (1, 1, n);

    while (m--)
    {
        int type;
        std::cin >> type;
        if (type == 1)
        {
            int l, r;
            std::cin >> l >> r;
            std::cout << get(1, 1, n, l, r) << "\n";
        }
        else if (type == 2)
        {
            int l, r, x;
            std::cin >> l >> r >> x;
            update1(1, 1, n, l, r, x);
        }
        else
        {
            int k, x;
            std::cin >> k >> x;
            update2(1, 1, n, k, x);
        }
    }

    return 0;
}
