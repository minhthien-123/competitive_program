#include <bits/stdc++.h>
#define ull unsigned long long

const ull maxn = 1e7;

ull n, i, d, a[maxn + 7], ans = 1;
bool flag = true;

bool isPrime(ull a){
    for(i = 2; i * i <= sqrt(a); i++){
        if(a % i == 0) return false;
    }
    return true;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    std::freopen("npri11.inp", "r", stdin);
    std::freopen("npri11.out", "w", stdout);

    std::cin >> n;
    if (isPrime(n)){
        std::cout << 0;
        return 0;
    }

    i = 2;
    d = 0;
    while (n > 1){
        while (n % i == 0 && n > 1){
            a[d]++;
            n /= i;
            flag = true;
            //std::cout << i << " ";
        }
        if (flag == true) d++;
        flag = false;
        i++;
    }

    for (i = 0; i < d; i++)
        ans *= (a[i] + 1);

    std::cout << ans - d;

    return 0;
}