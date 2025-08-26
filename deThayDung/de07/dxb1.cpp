#include <bits/stdc++.h>

long long m, n;

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen("dxb1.inp", "r", stdin);
    std::freopen("dxb1.out", "w", stdout);

    std::cin >> m >> n;
    m = m / 2 + (m % 2 != 0);
    std::cout << m * n << " " << m * n - (m % 2 != 0) * n;
}