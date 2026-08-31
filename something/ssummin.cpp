#include <bits/stdc++.h>
#define task "a"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e6;

int n;
int a[maxn];

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
    int ans = LLONG_MAX;
    int s = 0;
    for (int i = 1; i <= n; i++)
    {
        s = std::min(s, s + a[i]);
        ans = std::min(ans, s);
    }

    std::cout << ans;

    return 0;
}
