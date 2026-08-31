#include <bits/stdc++.h>
#define int long long

signed main(){
    int t;
    std::cin >> t;

    while (t--){
        int a, b;
        std::cin >> a >> b;
        int u = std::__gcd(a, b), k = 1, s = a / u;
        while (b * (s * k - 1) - a <= 0)
            k++;

        std::cout << b * (s * k - 1) - a << "\n";
    }
}

