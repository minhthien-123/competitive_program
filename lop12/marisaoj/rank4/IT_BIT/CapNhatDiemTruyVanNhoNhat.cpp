#include <bits/stdc++.h>
#define task ""  // Use the actual task name if file I/O is needed
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5 + 7;
const int inf  = 1e18;

int n, q;
int a[maxn], st[4 * maxn];

void update(int id, int l, int r, int pos, int val)
{
    if (pos < l || pos > r)
    {
        return;
    }

    if (l == r)
    {
        st[id] += val;
        return;
    }

    int mid = l + r >> 1;
    update(2 * id, l, mid, pos, val);
    update(2 * id + 1, mid + 1, r, pos, val);
    st[id] = std::min(st[id * 2], st[id * 2 + 1]);
}

int get(int id, int l, int r, int u, int v)
{
    if (v < l || r < u)
    {
        return inf;
    }
    if (u <= l && r <= v)
    {
        return st[id];
    }

    int mid = l + r >> 1;
    int get1 = get(id * 2, l, mid, u, v);
    int get2 = get(id * 2 + 1, mid + 1, r, u, v);
    return std::min(get1, get2);
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
        update(1, 1, n, i, a[i]);
    }

    while (q--)
    {
        int type, x, y;
        std::cin >> type >> x >> y;
        if (type == 1)
        {
            update(1, 1, n, x, y);
        }
        else
        {
            std::cout << get(1, 1, n, x, y) << "\n";
        }
    }

    return 0;
}
