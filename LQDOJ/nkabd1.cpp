#include <bits/stdc++.h>

bool pp(long long x){
    long long res = -x;
    for (long long i = 1; i <= sqrt(x); i++){
        if (x % i == 0){
            res += i;
            if (i * i != x){
                res += x / i;
            }
        }
    }

    return res > x;
}

long long l, r, ans = 0;

int main(){
    std::cin >> l >> r;
    for (long long i = l; i <= r; i++)
        if (pp(i))
            ans++;

    std::cout << ans;

    return 0;
}