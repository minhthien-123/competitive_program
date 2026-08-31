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
        int n;
        std::cin >> n;
        int a[n + 7];

        for (int i = 1; i <= n; i++) {
            std::cin >> a[i];
        }

        for (int i = 1; i < n; i++){
            if (a[i] == a[i + 1]){
                if (a[n - i + 1] != a[i + 1]){
                    std::swap(a[i], a[n - i + 1]);
                }
            }
        }

        for (int i = 2; i <= n; i++){
            if (a[i] == a[i - 1]){
                if (a[n - i + 1] != a[i - 1]){
                    std::swap(a[i], a[n - i + 1]);
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++){
            //std::cout << a[i] << " ";
            if (a[i] == a[i - 1]){
                ans++;
            }
        }

        //std::cout << "\n";
        std::cout << ans << "\n";
    }

    return 0;
}

