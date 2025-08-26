#include <bits/stdc++.h>
#define task "stat"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;
const int inf  = 1e18;

int n;
int a[maxn + 7], b[maxn + 7];

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
        std::cin >> a[i];
        b[i] = a[i];
    }

    std::sort(b + 1, b + n + 1);

    for (int i = 1; i <= n; i++)
    {
        std::cout << std::lower_bound(b + 1, b + n + 1, a[i]) - b - 1 << " " << n - (std::upper_bound(b + 1, b + n + 1, a[i]) - b - 1) << "\n";
    }

    return 0;
}
