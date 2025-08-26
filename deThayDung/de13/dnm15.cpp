#include <bits/stdc++.h>

long long x;
int n = 10, m, d = 0;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    std::freopen("dnm15.inp", "r", stdin);
    std::freopen("dnm15.out", "w", stdout);

    std::cin >> x;
    while (x > 0){
        m = x % 10;
        n = std::min(n, m);
        x /= 10;
        d++;
    }

    if (n == 0)
        for (int i = 1; i < d; i++)
            std::cout << 9;
    else
        for (int i = 1; i <= d; i++)
            std::cout << n;

    return 0;
}