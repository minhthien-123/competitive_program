#include <bits/stdc++.h>
#define task ""
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

void sub1(int n, int k){
    int ans = 1, tmp = 0;
    while (tmp < k){
        if ((ans % n) != 0){
            tmp++;
        }

        if (tmp == k){
            std::cout << ans << "\n";
        }

        ans++;
    }
}

void sub2(int n, int k){
    int l = 1, r = 2e9, ans;
        while (l <= r){
            int m = r - (r - l) / 2;
            if (m - (m / n) >= k){
                if (m % n != 0){
                    ans = m;
                }
                r = m - 1;
            }else{
                l = m + 1;
            }
        }
    std::cout << ans << "\n";
}
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
        int n, k;
        std::cin >> n >> k;

        if (n <= 1000){
            sub1();
        }else{
            sub2();
        }
    }

    return 0;
}

