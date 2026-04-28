#include <bits/stdc++.h>
#define task ""
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5 + 7;

int st[4 * maxn], a[maxn], lazy[4 * maxn];
int n, q;

void build(int id, int l, int r)
{
    if (l == r)
    {
        st[id] = a[l];
        return;
    }

    int mid = (l + r) >> 1;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    st[id] = st[id * 2] + st[id * 2 + 1];
}

void fix(int id, int l, int r)
{
    if (!lazy[id]) return;
    st[id] += lazy[id];

    if (l != r)
    {
        lazy[id * 2] += lazy[id];
        lazy[id * 2 + 1] += lazy[id];
    }

    lazy[id] = 0;
}

void update(int id, int l, int r, int u, int v, int val)
{
    fix(id, l, r);
    if (v < l || r < u) return;
    if (l >= u && r <= v)
    {
        lazy[id] += val;
        fix(id, l, r);
        return;
    }
    int mid = (l + r) >> 1;
    update(id * 2, l, mid, u, v, val);
    update(id * 2 + 1, mid + 1, r, u, v, val);
    st[id] = st[id * 2] + st[id * 2 + 1];
}

int get(int id, int l, int r, int u, int v)
{
    fix(id, l, r);
    if (v < l || r < u) return 0;
    if (l >= u && r <= v) return st[id];
    int mid = (l + r) >> 1;
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

    std::cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }

    build(1, 1, n);

    while (q--)
    {
        int type, l, r, val;
        std::cin >> type >> l >> r;
        if (type == 1)
        {
            std::cin >> val;
            update(1, 1, n, l, r, val);
        }
        else
        {
            std::cout << get(1, 1, n, l, r) << "\n";
        }
    }

    return 0;
}
