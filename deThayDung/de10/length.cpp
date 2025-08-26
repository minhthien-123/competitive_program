#include <bits/stdc++.h>

long double a, b, c, s, s1, s2, p;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    std::freopen("length.inp", "r", stdin);
    std::freopen("length.out", "w", stdout);

    std::cin >> a >> b >> c >> s;
    p = (a + b + c) / 2;
    //std::cout << p << "\n";
    s2 = sqrt(p * (p - a) * (p - b) * (p - c));
    s1 = s2 - s;

    //std::cout << s1 << " " << s2 << "\n";

    std::cout << std::setprecision(2) << std::fixed << a * sqrt(s1 / s2);

    return 0;
}