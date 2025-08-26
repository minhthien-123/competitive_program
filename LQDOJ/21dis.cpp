#include <bits/stdc++.h>
#define task "21dis"
#define ll long long

int n, mn = INT_MAX, mx = INT_MIN;

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen(task".inp", "r", stdin);
    std::freopen(task".out", "w", stdout);

    std::cin >> n;
    for (int i = 1, x; i <= n; i++){
        std::cin >> x;
        mn = std::min(mn, x);
        mx = std::max(mx, x);
    }

    std::cout << mx - mn;

    return 0;
}
