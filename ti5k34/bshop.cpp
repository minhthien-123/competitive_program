#include <bits/stdc++.h>
#define task "bshop"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5 + 7;
const int inf  = 1e18;

int n;
int st[maxn * 4], b[maxn], c[maxn];
ii a[maxn];

bool cmp(ii a, ii b)
{
    if (a.fi == b.fi) return a.se > b.se;
    return a.fi < b.fi;
}

void build_tree(int id, int l, int r)
{
    if (l == r)
    {
        st[id] = c[l];
        return;
    }

    int mid = (l + r) >> 1;
    build_tree(id * 2, l, mid);
    build_tree(id * 2 + 1, mid + 1, r);

    st[id] = std::max(st[id * 2], st[id * 2 + 1]);
}

int get(int id, int l, int r, int x, int y)
{
    if (r < x || l > y) return 0;
    if (x <= l && r <= y) return st[id];
    int mid = (l + r) >> 1;
    return std::max(get(id * 2, l, mid, x, y), get(id * 2 + 1, mid + 1, r, x, y));
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
        std::cin >> a[i].fi >> a[i].se;
    }

    std::sort(a + 1, a + n + 1, cmp);

    for (int i = 1; i <= n; i++)
    {
        b[i] = a[i].fi;
        c[i] = a[i].se;
    }

    build_tree(1, 1, n);

    int q;
    std::cin >> q;
    while (q--)
    {
        int x, y;
        std::cin >> x >> y;
        int l = std::lower_bound(b + 1, b + n + 1, x) - b;
        int r = std::upper_bound(b + 1, b + n + 1, y) - b - 1;

        std::cout << get(1, 1, n, l, r) << "\n";
    }

    return 0;
}
