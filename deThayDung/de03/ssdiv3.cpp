#include <bits/stdc++.h>

long long ans = 0, n;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    std::freopen("ssdiv3.inp", "r", stdin);
    std::freopen("ssdiv3.out", "w", stdout);

    std::cin >> n;
    while (n--){
        long long x;
        std::cin >> x;
        if (x % 2 != 0 && x % 3 == 0)
            ans += x;
    }

    std::cout << ans;

    return 0;
}