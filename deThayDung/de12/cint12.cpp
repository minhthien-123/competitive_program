#include <bits/stdc++.h>

unsigned long long a, b, c, d;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    std::freopen("cint12.inp", "r", stdin);
    std::freopen("cint12.out", "w", stdout);

    std::cin >> a >> b >> c >> d;
    if (a <= c)
        if (b <= c)
            std::cout << d + b - c - a + 2;
        else
            std::cout << std::max(b, d) - a + 1;
    else
        if (d <= a)
            std::cout << d + b - c - a + 2;
        else
            std::cout << std::max(b, d) - c + 1;

    return 0;
}
