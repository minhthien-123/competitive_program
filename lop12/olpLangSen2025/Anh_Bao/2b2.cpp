#include <bits/stdc++.h>
#define task "2b2"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e6;
const int maxd = 1e7;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

int n, m, k, l = 1, r = 0, ans, bs;
int a[maxn + 7], d[maxd + 7], res[maxn + 7], f[maxn + 7];

struct b2
{
    int l, r, id;
} q[maxn + 7];

bool cmp(b2 a, b2 b)
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
    while (l < q[i].l)
    {
        d[f[l - 1]]--;
        ans -= d[f[l - 1] ^ k];
        l++;
    }
    while (l > q[i].l)
    {
        l--;
        ans += d[f[l - 1] ^ k];
        d[f[l - 1]]++;
    }
    while (r < q[i].r)
    {
        r++;
        ans += d[f[r] ^ k];
        d[f[r]]++;
    }
    while (r > q[i].r)
    {
        d[f[r]]--;
        ans -= d[f[r] ^ k];
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

    std::cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        f[i] = f[i - 1] ^ a[i];
    }
    bs = sqrt(n);
    for (int i = 1; i <= m; i++)
    {
        std::cin >> q[i].l >> q[i].r;
        q[i].id = i;
    }
    d[0] = 1;
    std::sort(q + 1, q + m + 1, cmp);
    for (int i = 1; i <= m; i++)
    {
        mo(i);
        res[q[i].id] = ans;
    }
    for (int i = 1; i <= m; i++)
    {
        std::cout << res[i] << '\n';
    }

    return 0;
}
