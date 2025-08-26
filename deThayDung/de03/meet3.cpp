#include <bits/stdc++.h>

long double v1, v2, s;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    std::freopen("meet3.inp", "r", stdin);
    std::freopen("meet3.out", "w", stdout);

    std::cin >> v1 >> v2 >> s;
    s = s - 2.0 * v1;
    if (s <= 0){
        std::cout << -1;
        return 0;
    }

    std::cout << std::setprecision(3) << std::fixed << (s * v1) / (v1 + v2) + 2.0 * v1;

    return 0;
}