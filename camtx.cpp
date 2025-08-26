#include <bits/stdc++.h>
#define task "camtx"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e6 + 7;

int a[maxn];
int n, k, h;

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> n >> k >> h;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        a[i] += a[i - 1];
    }

    h *= 2;
    k = h / k;
    if (k >= n)
    {
        std::cout << a[n];
    }
    else
    {
        int ans = LLONG_MIN;
        for (int i = 1; i <= n - k; i++)
        {
            ans = std::max(ans, a[i + k] - a[i - 1]);
        }

        std::cout << ans;
    }

    return 0;
}
