#include <bits/stdc++.h>
#define task "square"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

bool check(int a, int b, int c, int d, int m){
    bool tmp1 = false, tmp2 = false;
    if (a % m == 0 || b % m == 0) tmp1 = true;
    else                          tmp1 = (b / m - a / m) > 0;
    if (c % m == 0 || d % m == 0) tmp2 = true;
    else                          tmp2 = (d / m - c / m) > 0;

    return tmp1 && tmp2;
}

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r")){
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    int n;
    std::cin >> n;
    while (n--){
        int a, b, c, d;
        std::cin >> a >> b >> c >> d;

        int l = 1, r = std::max(b, d), ans = 1;

        if (r - l <= 1000){
            for (int i = l; i <= r; i++){
                if (check(a, b, c, d, i)){
                    ans = i;
                }
            }
        }else{
            while (l <= r){
                int mid = (l + r) / 2;
                std::cout << mid << " ";
                if (check(a, b, c, d, mid)){
                    l = mid + 1;
                    ans = mid;
                }else{
                    r = mid - 1;
                }
            }
        }

        std::cout << ans << "\n";
    }

    return 0;
}

