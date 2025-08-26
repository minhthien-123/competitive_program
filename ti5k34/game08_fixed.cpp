#include <bits/stdc++.h>
#define task "game08"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;
const int inf = 1e18;

int n, m;
int a[maxn + 7], b[maxn + 7];

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

    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        std::cin >> b[i];
    }

    std::sort(a + 1, a + n + 1);
    std::sort(b + 1, b + n + 1);

    int ans = inf;
    int i = 1;
    while (i <= n)
    {
        int tmp = a[i] * -1;
        int temp = std::lower_bound(b + 1, b + n + 1, tmp) - b;
        if (temp == n + 1)
        {
            ans = std::min(ans, abs(a[i] + b[n]) * 1LL);
            i++;
            continue;
        }
        if (temp == 1)
        {
            ans = std::min(ans, abs(a[i] + b[1]) * 1LL);
            i++;
            continue;
        }
        ans = std::min({ans, abs(a[i] + b[temp]) * 1LL, abs(a[i] + b[temp - 1]) * 1LL});
        i++;
    }

    std::cout << ans;

    return 0;
}
