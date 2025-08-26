#include <bits/stdc++.h>

int n, ans, d, en;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    std::freopen("even11.inp", "r", stdin);
    std::freopen("even11.out", "w", stdout);

    std::cin >> n;
    en = ans = d = 0;
    for (int i = 1; i <= n; i++){
        long long x;
        std::cin >> x;
        if (x % 2 == 0 && x > 0)
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
        ans = d;
        en = n + 1;
    }

    if (ans == 0)
        std::cout << 0;
    else
        std::cout << ans << "\n" << en - ans;

    return 0;
}