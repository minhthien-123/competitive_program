#include <bits/stdc++.h>
#define task "prx"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    int t;
    std::cin >> t;
    while (t--){
        int n;
        std::cin >> n;
        int a[n + 7];
        for (int i = 1; i <= n; i++)
        {
            std::cin >> a[i];
        }
        int ans = a[1];
        int sum = a[1];
        for(int i = 2; i <= n; i++){
            if((abs(a[i]) % 2) != (abs(a[i - 1]) % 2))
            {
                sum = std::max(a[i], sum + a[i]);
                ans = std::max(ans, sum);
            }
            else
            {
                ans = std::max(ans, sum);
                sum = a[i];
            }
        }

        std::cout << ans << "\n";
    }

    return 0;
}
