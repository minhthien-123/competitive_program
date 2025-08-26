#include <bits/stdc++.h>
#define ll long long
ll n, d, ans = LLONG_MIN, en;

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen("16od.inp", "r", stdin);
    std::freopen("16od.out", "w", stdout);

    std::cin >> n;
    d = 0;
    for (ll i = 1, x; i <= n; i++){
        std::cin >> x;
        if (x % 2 == 1 && x > 0)
            d++;
        else{
            if (d > ans){
                ans = d;
                en = i;
            }
            d = 0;
        }
    }

    if (d > ans){
        ans =  d;
        en = n + 1;
    }

    if (ans == LLONG_MIN || ans == 0) std::cout << 0;
    else                              std::cout << ans << "\n" << en - ans;

    return 0;
}
