#include <bits/stdc++.h>
#define task "nklineup"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 5e4 + 7;
const int inf  = 1e18;

struct tree
{
    int Min, Max, val;
};

tree st[4 * maxn];
int n, q, a[maxn];

tree merge(tree a, tree b)
{
    tree res;
    res.Min = std::min(a.Min, b.Min);
    res.Max = std::max(a.Max, b.Max);
    res.val = res.Max - res.Min;

    return res;
}

void build(int id, int l, int r)
{
    if (l == r)
    {
        st[id] = {a[l], a[l], 0};
        return;
    }
    int mid = (l + r) >> 1;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    st[id] = merge(st[id * 2], st[id * 2 + 1]);
}

tree get(int id, int l, int r, int u, int v)
{
    if (v < l || r < u)
    {
        return {inf, -inf, 0};
    }
    if (u <= l && r <= v)
    {
        return st[id];
    }

    int mid = (l + r) >> 1;
    tree get1 = get(id * 2, l, mid, u, v);
    tree get2 = get(id * 2 + 1, mid + 1, r, u, v);
    return merge(get1, get2);
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
        int x, y;
        std::cin >> x >> y;
        tree res = get(1, 1, n, x, y);
        std::cout << res.val << "\n";
    }

    return 0;
}
