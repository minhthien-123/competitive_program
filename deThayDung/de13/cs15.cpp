#include <bits/stdc++.h>

const long long mod = 2020;
long long n, a, b;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    std::freopen("cs15.inp", "r", stdin);
    std::freopen("cs15.out", "w", stdout);

    std::cin >> n;

    if (n % 3 == 0){
        a = n / 3;
        b = (n + 1) * (n + 2);
    }else if ((n + 1) % 3 == 0){
        a = (n + 1) / 3;
        b = n * (n + 2);
    }else{
        a = (n + 2) / 3;
        b = n * (n + 1);
    }

    std::cout << (a * b) % mod << "\n";

    return 0;
}