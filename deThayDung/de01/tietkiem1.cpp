#include <bits/stdc++.h>
#define ld long double

ld power(ld a, ld n){
    if (n == 0) return 1;
    if (n == 1) return a;
    ld tmp = power(a, n / 2);
    return tmp * tmp;
}

ld a, n;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    freopen("tietkiem1.inp", "r", stdin);
    freopen("tietkiem1.out", "w", stdout);

    std::cin >> a >> n;

    std::cout << std::setprecision(3) << std::fixed << power(1.003, n) * a << "\n";

    return 0;
}