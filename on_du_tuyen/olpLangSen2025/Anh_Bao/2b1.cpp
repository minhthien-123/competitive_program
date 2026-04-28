#include <bits/stdc++.h>
#define task "2b1"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 2e6;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

struct b1
{
    int l, r, id;
} q[maxn + 7];

int n, t, bs, l, r, ans;
int a[maxn + 7], d[maxn + 7], res[maxn + 7];

bool cmp(b1 a, b1 b)
{
    if (a.l / bs != b.l / bs)
    {
        return a.l < b.l;
    }
    else
    {
        int id = (a.l + bs - 1) / bs;
        return (id & 1) ? a.r < b.r : a.r > b.r;
    }
}

void mo(int i)
{
    while (l > q[i].l)
    {
        l--;
        ans -= d[a[l]] * d[a[l]] * a[l];
        d[a[l]]++;
        ans += d[a[l]] * d[a[l]] * a[l];
    }
    while (r < q[i].r)
    {
        r++;
        ans -= d[a[r]] * d[a[r]] * a[r];
        d[a[r]]++;
        ans += d[a[r]] * d[a[r]] * a[r];
    }
    while (l < q[i].l)
    {
        ans -= d[a[l]] * d[a[l]] * a[l];
        d[a[l]]--;
        ans += d[a[l]] * d[a[l]] * a[l];
        l++;
    }
    while (r > q[i].r)
    {
        ans -= d[a[r]] * d[a[r]] * a[r];
        d[a[r]]--;
        ans += d[a[r]] * d[a[r]] * a[r];
        r--;
    }
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

    std::cin >> n >> t;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }
    bs = sqrt(n);
    for (int i = 1; i <= t; i++)
    {
        std::cin >> q[i].l >> q[i].r;
        q[i].id = i;
    }
    std::sort(q + 1, q + t + 1, cmp);

    for (int i = 1; i <= t; i++)
    {
        mo(i);
        res[q[i].id] = ans;
    }

    for (int i = 1; i <= t; i++)
    {
        std::cout << res[i] << "\n";
    }

    return 0;
}
