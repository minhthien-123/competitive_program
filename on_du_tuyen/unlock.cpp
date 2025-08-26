#include <bits/stdc++.h>
#define task "unlock"
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
int a[2 * maxn + 7], pre[2 * maxn + 7];

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
        a[n + i] = a[i] + m;
    }

    std::sort(a + 1, a + 2 * n + 1);

    pre[0] = 0;
    for (int i = 1; i <= 2 * n; i++)
    {
        pre[i] = pre[i - 1] + a[i];
    }

    int ans = inf;
    for (int i = 1; i <= n + 1; i++)
    {
        int j = i + n / 2;
        int l = a[j] * (n / 2) - (pre[j - 1] - pre[i - 1]);
        int r = (pre[i + n - 1] - pre[j - 1]) - a[j] * (n - n / 2);
        ans = std::min(ans, l + r);
    }


    std::cout << ans;
    return 0;
}
