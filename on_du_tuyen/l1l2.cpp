#include <bits/stdc++.h>
#define task "L1L2"
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
int dp[maxn + 7], f[maxn + 7], ans;
int st[4 * maxn + 7];

void update(int id, int l, int r, int pos, int val)
{
    if (pos < l || pos > r)
    {
        return;
    }
    if (l == r)
    {
        st[id] = std::max(st[id], val);
        return;
    }
    int mid = (l + r) >> 1;
    update(id * 2, l, mid, pos, val);
    update(id * 2 + 1, mid + 1, r, pos, val);
    st[id] = std::max(st[id * 2], st[id * 2 + 1]);
}

int get(int id, int l, int r, int u, int v)
{
    if (v < l || r < u)
    {
        return 0;
    }
    if (u <= l && r <= v)
    {
        return st[id];
    }
    int mid = (l + r) >> 1;
    return std::max(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task ".inp", "r"))
    {
        std::freopen(task ".inp", "r", stdin);
        std::freopen(task ".out", "w", stdout);
    }

    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }

    for (int i = 1; i <= n; i++)
    {
        std::vector<ii> v;
        for (int j : {-1, 0, 1})
        {
            int tmp = a[i] + j;
            v.pb({tmp, get(1, 1, n, 1, tmp - 1) + 1});
        }

        for (ii j : v)
        {
            update(1, 1, n, j.fi, j.se);
            ans = std::max(ans, j.se);
        }
    }

    std::cout << ans;

    return 0;
}
