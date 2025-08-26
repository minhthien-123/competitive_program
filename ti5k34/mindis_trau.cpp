#include <bits/stdc++.h>
#define task "mindis"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e6;
const int inf  = 1e18;

int n, q;
int a[maxn + 7];

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".ans", "w", stdout);
    }

    std::cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }

    while (q--)
    {
        int x, ans = inf;
        std::cin >> x;
        for (int i = 1; i <= n; i++)
        {
            ans = std::min(ans, abs(a[i] - x));
        }
        std::cout << ans << "\n";
    }

    return 0;
}
