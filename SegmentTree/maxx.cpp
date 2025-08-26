#include <bits/stdc++.h>
#define task ""
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5 + 7;
const int inf  = 1e18;

int n, m;
int a[maxn], st[4 * maxn];

void build_tree(int id, int l, int r)
{
    if (l == r)
    {
        st[id] = a[l];
        return;
    }

    int mid = (l + r) / 2;
    build_tree(id * 2, l, mid);
    build_tree(id * 2 + 1, mid + 1, r);
    st[id] = std::max(st[id * 2], st[id * 2 + 1]);
}

int get(int id, int l, int r, int x, int y)
{
    if (r < x || l > y) return -inf;
    if (x <= l && r <= y) return st[id];

    int mid = (l + r) / 2;
    int left = get(id * 2, l, mid, x, y);
    int right = get(id * 2 + 1, mid + 1, r, x, y);
    return std::max(left, right);
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

    build_tree(1, 1, n);

    while (m--)
    {
        int x, y;
        std::cin >> x >> y;
        std::cout << get(1, 1, n, x, y) << "\n";
    }

    return 0;
}
