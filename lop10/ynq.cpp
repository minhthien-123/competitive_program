#include <bits/stdc++.h>
#define task "ynq"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen(task".inp", "r", stdin);
    std::freopen(task".out", "w", stdout);

    int t;
    std::cin >> t;
    while (t--){
        int n, d = 0;
        std::cin >> n;
        for (int i = 1, x; i <= n; i++){
            std::cin >> x;
            if (x % 2 != 0){
                d++;
            }
        }

        if (d % 2 != 0){
            std::cout << "NO\n";
        }else{
            std::cout << "YES\n";
        }
    }

    return 0;
}
