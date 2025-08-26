#include <bits/stdc++.h>
#define task ""
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;
const int inf  = 1e18;

int n, q;
int a[maxn + 7];

struct tree
{
    int pre, suf, sum, val;
};

tree st[4 * maxn + 7];

tree merge(tree x, tree y)
{
    tree res;
    res.pre = std::max(x.pre, x.sum + y.pre);
    res.suf = std::max(y.suf, y.sum + x.suf);
    res.sum = x.sum + y.sum;
    res.val = std::max({x.val, y.val, x.suf + y.pre});
    return res;
}

void build(int id, int l, int r)
{
    if (l == r)
    {
        st[id] = {a[l], a[l], a[l], a[l]};
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    st[id] = merge(st[id * 2], st[id * 2 + 1]);
}

tree get(int id, int l, int r, int u, int v)
{
    if (v < l || r < u)
    {
        return {-inf, -inf, 0, -inf};
    }
    if (u <= l && r <= v)
    {
        return st[id];
    }
    int mid = (l + r) / 2;
    return merge(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
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

    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }

    build(1, 1, n);

    std::cin >> q;

    while (q--)
    {
        int l, r;
        std::cin >> l >> r;
        tree res = get(1, 1, n, l, r);
        std::cout << res.val << "\n";
    }

    return 0;
}
