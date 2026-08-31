#include <bits/stdc++.h>
#define int long long

int gcd(int a, int b){
    return std::__gcd(a, b);
}

int lcm(int a, int b){
    return a / gcd(a, b) * b;
}

signed main(){
    int t;
    std::cin >> t;
    while (t--){
        int a, b, c;
        std::cin >> a >> b >> c;
        int ans1 = b / gcd(a, b);
        int ans2 = c / gcd(b, c);
        int ans3 = a / gcd(c, a);

        std::cout << lcm(ans1, lcm(ans2, ans3)) << "\n";

        //std::cout << ans1 << " " << ans2 << " " << ans3 << "\n";
    }
}

