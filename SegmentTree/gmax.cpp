#include <bits/stdc++.h>
#define task "gmax"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5 + 7;
const int inf  = 1e18;

struct tree
{
    int Min, Max, val;
};

int n, m;
int a[maxn];
tree st[4 * maxn];

tree merge(tree x, tree y)
{
    tree res;
    res.Min = std::min(x.Min, y.Min);
    res.Max = std::max(x.Max, y.Max);
    res.val = std::max(y.Max - y.Min, std::max(x.val, y.val));
    return res;
}

void buildTree(int id, int l, int r)
{
    if (l == r)
    {
        st[id].Min = std::min(a[l], a[l - 1]);
        st[id].Max = a[r];
        st[id].val = a[r] - a[l - 1];
        return;
    }

    int mid = l + r >> 1;
    buildTree(id * 2, l, mid);
    buildTree(id * 2 + 1, mid + 1, r);

    st[id] = merge(st[id * 2], st[id * 2 + 1]);
}

tree get(int id, int l, int r, int x, int y)
{
    if (y < l || r < x) return {inf, -inf, 0};
    if (x <= l && r <= y) return st[id];

    int mid = l + r >> 1;
    return merge(get(id * 2, l, mid, x, y), get(id * 2 + 1, mid + 1, r, x, y));
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
        a[i] += a[i - 1];
    }

    buildTree(1, 1, n);

    std::cin >> m;
    while (m --)
    {
        int x, y;
        std::cin >> x >> y;
        std::cout << get(1, 1, n, x, y).val << "\n";
    }

    return 0;
}
