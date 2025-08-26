#include <bits/stdc++.h>
#define task "tienks"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 12000;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;

struct tienks
{
    int a, b, c;
} a[maxn + 7];

bool cmp(tienks x, tienks y)
{
    if (x.b == y.b)
    {
        return x.a < y.a;
    }
    return x.b < y.b;
}

int n;
int t[maxn + 7], dp[maxn + 7];

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
        std::cin >> a[i].a >> a[i].b >> a[i].c;
    }
    std::sort(a + 1, a + n + 1, cmp);

    for (int i = 1; i <= n; i++)
    {
        t[i] = a[i].b;
    }

    for (int i = 1; i <= n; i++)
    {
        int id = std::upper_bound(t + 1, t + n + 1, a[i].a) - (t + 1);
        dp[i] = std::max(dp[i - 1], dp[id] + a[i].c);
    }

    std::cout << dp[n];

    return 0;
}
