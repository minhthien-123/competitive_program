#include <bits/stdc++.h>
#define task "gem"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;
const int inf  = 1e18;

int n, k;
int a[maxn + 7], b[maxn + 7];

bool check(double x)
{
    double s[maxn + 7];
    for (int i = 1; i <= n; i++)
    {
        s[i] = (double)a[i] - (double)x * b[i];
    }

    std::sort(s + 1, s + n + 1, std::greater<int>());
    double S = 0.0;
    for (int i = 1; i <= k; i++)
    {
        S += s[i];
    }

    return S >= 0;
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i] >> b[i];
    }

    double l = 0, r = 1e18, ans = -1;
    for (int cnt = 1; cnt <= 100; cnt++)
    {
        int mid = (l + r) / 2;
        if (check(mid))
        {
            ans = mid;
            l = mid;
        }
        else
        {
            r = mid;
        }
    }

    std::cout << std::fixed << std::setprecision(10) << ans << "\n";

    return 0;
}
