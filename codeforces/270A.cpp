#include <bits/stdc++.h>
#define task "codeforces"
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

    int t;
    std::cin >> t;
    while (t--){
        int a;
        std::cin >> a;
        a = (180 - a);
        if (360 % a == 0) std::cout << "YES\n";
        else              std::cout << "NO\n";
    }

    return 0;
}

// 180 * (n - 2) = a * n
// (180 - a) * n = 360
