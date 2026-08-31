#include <bits/stdc++.h>

bool isPrime(int x){
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return false;
    return true;
}

const int maxn = 1e6 + 7;

bool prime[maxn + 7];
int n;

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen("16fp.inp", "r", stdin);
    std::freopen("16fp.out", "w", stdout);

    for (int i = 1; i <= maxn; i++)
        prime[i] = true;
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= maxn; i++)
        if (prime[i])
            for (int j = i * i; j <= maxn; j += i)
                prime[j] = false;

    std::cin >> n;
    if (n <= 1000){
        for (int i = 1, x; i <= n; i++){
            std::cin >> x;
            if (isPrime(x)){
                std::cout << i;
                return 0;
            }
        }

        std::cout << 0;
    }else{
        for (int i = 1, x; i <= n; i++){
            std::cin >> x;
            if (x > 0)
                if (prime[x]){
                    std::cout << i;
                    return 0;
                }
        }

        std::cout << 0;
    }

    return 0;
}
