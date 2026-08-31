#include <bits/stdc++.h>
#define int long long

const int maxn = 1e5 + 7;
const int inf = 1e18 + 7;
int n, m;
int a[maxn], st[4 * maxn];

void buildTree(int id, int l, int r)
{
    if (l == r)
    {
        st[id] = a[l];
        return;
    }

    int mid = (l + r) / 2;

    buildTree(id * 2, l, mid);
    buildTree(id * 2 + 1, mid + 1, r);

    int upd1 = st[id * 2];
    int upd2 = st[id * 2 + 1];
    st[id] = std::min(upd1, upd2);
}

void update(int id, int l, int r, int i, int val)
{
    if (i < l || i > r)
        return;
    if (l == r)
    {
        st[id] = val;
        return;
    }

    int mid = l + r >> 1;
    update(id * 2, l, mid, i, val);
    update(id * 2 + 1, mid + 1, r, i, val);
    int upd1 = st[id * 2];
    int upd2 = st[id * 2 + 1];
    st[id] = std::min(upd1, upd2);
}

int get(int id, int l, int r, int u, int v)
{
    if (v < l || r < u)
        return inf;
    if (u <= l && r <= v)
        return st[id];

    int mid = l + r >> 1;
    int get1 = get(id * 2, l, mid, u, v);
    int get2 = get(id * 2 + 1, mid + 1, r, u, v);

    return std::min(get1, get2);
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    // std::freopen("listman.inp", "r", stdin);
    // std::freopen("listman.out", "w", stdout);

    std::cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        if (a[i] <= 0)
        {
            a[i] = inf;
        }
    }

    // std::cout << inf;

    buildTree(1, 1, n);

    while (m--)
    {
        char c;
        std::cin >> c;
        if (c == 'S')
        {
            int u, v;
            std::cin >> u >> v;
            if (v <= 0)
            {
                v = inf;
            }
            update(1, 1, n, u, v);
        }
        else
        {
            int ans = get(1, 1, n, 1, n);
            if (ans == inf)
            {
                std::cout << 0;
            }
            else
            {
                std::cout << ans;
            }
            std::cout << "\n";
        }
    }

    return 0;
}
