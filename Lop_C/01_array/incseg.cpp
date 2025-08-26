#include <bits/stdc++.h>
#define task "incseg"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

int n, a[1000005], dp[1000005], mx = 0;

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    //std::freopen(task".inp", "r", stdin);
    //std::freopen(task".out", "w", stdout);

    std::cin >> n;
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    for (int i = 1; i < n; i++)
        if (a[i] >= a[i - 1]){
            dp[i] = dp[i - 1] + 1;
            mx = std::max(mx, dp[i]);
        }

    std::cout << mx + 1;

    return 0;

    return 0;
}
