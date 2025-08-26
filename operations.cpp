#include <bits/stdc++.h>
#define task "operations"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r")){
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    int a, b;
    std::cin >> a >> b;
    int ans = 0;
    while (b)
    {
        ans += a / b;
        int tmp = a % b;
        a = b;
        b = tmp;
    }

    std::cout << ans;

    return 0;
}