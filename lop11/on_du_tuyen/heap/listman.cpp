#include <bits/stdc++.h>
#define task "listman"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

int n, m;
int a[maxn + 7];
int st[4 * maxn + 7];

void build(int id, int l, int r)
{
    if (l == r)
    {
        st[id] = a[l];
        return;
    }

    int mid = l + r >> 1;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);

    st[id] = std::min(st[id * 2], st[id * 2 + 1]);
}

void update(int id, int l, int r, int pos, int val)
{
    if (pos < l || pos > r)
    {
        return;
    }
    if (l == r)
    {
        st[id] = val;
        return;
    }

    int mid = l + r >> 1;
    update(id * 2, l, mid, pos, val);
    update(id * 2 + 1, mid + 1, r, pos, val);
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

    return std::min(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    if (std::fopen(task ".inp", "r"))
    {
        std::freopen(task ".inp", "r", stdin);
        std::freopen(task ".out", "w", stdout);
    }

    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        if (a[i] <= 0)
        {
            a[i] = inf;
        }
    }

    build(1, 1, n);

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
                std::cout << 0 << "\n";
            }
            else
            {
                std::cout << ans << "\n";
            }
        }
    }

    return 0;
}
