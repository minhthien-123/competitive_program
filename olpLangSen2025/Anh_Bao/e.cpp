#include <bits/stdc++.h>
#define task "e"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 2e5;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

int n, k, ans;
int st[4 * maxn + 7], a[maxn];

void build(int id, int l, int r)
{
    if (l == r)
    {
        st[id] = a[l];
        return;
    }

    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    st[id] = std::min(st[id * 2], st[id * 2 + 1]);
}

bool walk(int id, int l, int r, int u, int v, int val)
{
    if (v < l || r < u)
    {
        return 1;
    }

    if (u <= l && r <= v && val <= st[id])
    {
        ans = r;
        return 1;
    }

    if (l == r)
    {
        return 0;
    }

    int mid = (l + r) / 2;
    if (walk(id * 2, l, mid, u, v, val))
    {
        return walk(id * 2 + 1, mid + 1, r, u, v, val);
    }
    return 0;
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

    std::cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        a[i + n] = a[i];
    }

    for (int i = 1; i <= 2 * n; i++)
    {
        a[i] -= i * k;
    }
    build(1, 1, 2 * n);

    for (int i = 1; i <= n; i++)
    {
        ans = 0;
        walk(1, 1, 2 * n, i, i + n, a[i]);
        std::cout << ans % n + 1 << " ";
    }

    return 0;
}
