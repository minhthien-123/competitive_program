#include <bits/stdc++.h>

int n, a[1000005], ans = INT_MIN, mn;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    std::freopen("dif15.inp", "r", stdin);
    std::freopen("dif15.out", "w", stdout);

    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];

    mn = a[1];
    for (int i = 2; i <= n; i++){
        ans = std::max(ans, a[i] - mn);
        mn = std::min(mn, a[i]);
    }

    std::cout << ans;

    return 0;
}
