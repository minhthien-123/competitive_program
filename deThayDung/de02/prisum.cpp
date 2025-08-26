#include <bits/stdc++.h>

bool isPrime(long long x){
    if (x < 2) return false;
    else{
        for (long long i = 2; i <= sqrt(x); i++)
            if (x % i == 0) return false;
    }

    return true;
}

long long n, s, i, j;
bool a[1000009];

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    std::freopen("prisum.inp", "r", stdin);
    std::freopen("prisum.out", "w", stdout);

    std::cin >> n;

    for (i = 0; i <= 1e6; i++){
        a[i] = true;
    }

    a[0] = false;
    a[1] = false;
    for (i = 2; i * i <= 1e6; i++){
        if (a[i]){
            for (j = i * i; j <= 1e6; j += i){
                a[j] = false;
            }
        }
    }

    for(i = 2; i <= n; i++){
        //std::cout << a[i] << "\n";
        if (a[i]) s += i;
    }

    if (isPrime(s)) std::cout << s;
    else std::cout << -1;

    return 0;
}