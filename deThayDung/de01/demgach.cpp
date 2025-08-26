#include <bits/stdc++.h>

long long n, m;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    std::freopen("demgach.inp", "r", stdin);
    std::freopen("demgach.out", "w", stdout);

    std::cin >> n >> m;
    std::cout << (m + n - 2) * 2 << " " << m * n - (m + n - 2) * 2;

    return 0;
}