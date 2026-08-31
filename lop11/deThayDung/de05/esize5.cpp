#include <bits/stdc++.h>

long double x, y, del, l, s;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    std::freopen("esize5.inp", "r", stdin);
    std::freopen("esize5.out", "w", stdout);
    std::cin >> l >> s;

    l /= 2;
    del = l * l - 4 * s;
    x = (l - sqrt(del)) / 2;
    y = (l + sqrt(del)) / 2;

    std::cout << std::setprecision(2) << std::fixed << std::min(x, y) << "\n" << std::max(x, y);

    return 0;
}

// x^2 - Lx + S = 0
