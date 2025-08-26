#include <bits/stdc++.h>

long double v1, v2, s, s1;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    std::freopen("hwl11.inp", "r", stdin);
    std::freopen("hwl11.out", "w", stdout);

    std::cin >> v1 >> v2 >> s;
    if (v1 >= v2){
        std::cout << -1;
        return 0;
    }

    s1 = (v1 * v1) / (v2 - v1) + v1;
    if (s1 >= s){
        std::cout << -1;
        return 0;
    }

    std::cout << std::setprecision(3) << std::fixed << s1;

    return 0;
}