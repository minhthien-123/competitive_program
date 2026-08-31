#include <bits/stdc++.h>
#define ll long long

long double a, b, c, d, h;

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen("14are.inp", "r", stdin);
    std::freopen("14are.out", "w", stdout);

    std::cin >> a >> b >> c;
    d = (b - a) / 2;
    h = sqrt(c * c - d * d);
    h = h / 4;

    std::cout << std::setprecision(2) << std::fixed << (a + b) * h * 2 - h * h * 3.14;

    return 0;
}
