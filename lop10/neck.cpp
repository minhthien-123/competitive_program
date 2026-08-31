#include <bits/stdc++.h>
#define task "neck"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;
const int inf = 1e18;

int n;
int a[maxn + 7], dp1[maxn + 7], dp2[maxn + 7], st[4 * maxn + 7], f[maxn + 7];
std::vector<int> v;

void update(int id, int l, int r, int pos, int val)
{
    if (l > pos || r < pos)
        return;
    if (l == r)
    {
        st[id] = val;
        return;
    }
    int mid = (l + r) / 2;
    update(id * 2, l, mid, pos, val);
    update(id * 2 + 1, mid + 1, r, pos, val);
    st[id] = std::max(st[id * 2], st[id * 2 + 1]);
}
int get(int id, int l, int r, int u, int v)
{
    if (l > v || r < u)
    {
        return 0;
    }
    if (l <= u && v <= r)
    {
        return st[id];
    }
    int mid = (u + v) / 2;
    int get1 = get(id * 2, l, r, u, mid);
    int get2 = get(id * 2 + 1, l, r, mid + 1, v);
    return std::max(get1, get2);
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

    v.pb(0);
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        v.pb(a[i]);
    }

    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());

    for (int i = 1; i <= n; i++)
    {
        f[i] = std::lower_bound(v.begin(), v.end(), a[i]) - v.begin();
    }
    for (int i = n; i >= 1; i--)
    {
        dp1[i] = get(1, f[i] + 1, n, 1, n) + 1;
        update(1, 1, n, f[i], dp1[i]);
    }
    for (int i = 0; i <= 4 * n; i++)
    {
        st[i] = 0;
    }
    int ans = 0;
    for (int i = n; i >= 1; i--)
    {
        dp2[i] = get(1, 1, f[i] - 1, 1, n) + 1;
        ans = std::max(ans, dp2[i] + dp1[i] - 1);
        update(1, 1, n, f[i], dp2[i]);
    }
    std::cout << ans;

    return 0;
}
