#include <bits/stdc++.h>
#define task "wseq0"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e6;
const int inf  = 1e18;

int n;
int a[maxn + 7];

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
    }

    int x = -inf, y = 0;

    for (int i = 1; i <= n; i++)
    {
        int tmpx = std::max(x, y - a[i]);
        int tmpy = std::max(y, x + a[i]);
        x = tmpx;
        y = tmpy;
    }

    std::cout << -std::max(x, y);

    return 0;
}
