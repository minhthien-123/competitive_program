#include <bits/stdc++.h>
#define ull unsigned long long

const ull maxn = 1e7;
const ull maxx = 5e5 + 9;
const ull mod  = 1e9 + 7;
ull m, n, a[maxn], b[maxn], minPrime[maxn], degA[maxn], degB[maxn];
long long ans = 1;

ull power(ull a, ull b){
    if (b == 0) return 1 % mod;
    else{
        ull tmp = power(a, b / 2);
        if (b % 2 == 0)
            return tmp * tmp % mod;
        else
            return a * (tmp * tmp % mod) % mod;
    }
}

void sieveA(ull x){
    while (x != 1){
        ull p = minPrime[x];
        degA[p]++;
        x /= p;
    }
}

void sieveB(ull x){
    while (x != 1){
        ull p = minPrime[x];
        degB[p]++;
        x /= p;
    }
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen("23thtbgb4c2.inp", "r", stdin);
    std::freopen("23thtbgb4c2.out", "w", stdout);

    for (ull i = 2; i * i <= maxn; ++i) {
        if (minPrime[i] == 0) {
            for (ull j = i * i; j <= maxn; j += i) {
                if (minPrime[j] == 0) {
                    minPrime[j] = i;
                }
            }
        }
    }
    for (ull i = 2; i <= maxn; ++i) {
        if (minPrime[i] == 0) {
            minPrime[i] = i;
        }
    }

    m = 500000; n = m;
    for (ull i = 1; i <= n; i++) a[i] = n * i + n;
    for (ull i = 1; i <= m; i++) b[i] = n + n * 2 * i;

    /*for (ull i = 1; i <= n; i++) std::cout << minPrime[a[i]] << " ";
    std::cout << "\n";
    for (ull i = 1; i <= m; i++) std::cout << minPrime[b[i]] << " ";
    std::cout << "\n\n";*/

    for (ull i = 1; i <= n; i++) sieveA(a[i]);
    for (ull i = 1; i <= m; i++) sieveB(b[i]);

    for (ull i = 1; i < maxn; i++)
        if (degA[i] != 0)
            std::cout << i << "              " << degA[i] << " " << degB[i] << "\n";
    std::cout << "\n";

    /*for (ull i = 1; i < maxn; i++){
        if (degA[i] != 0 && degB[i] != 0){
            //std::cout << i << " " << std::min(degA[i], degB[i]) << " " << power(std::min(degA[i], degB[i]), i) << "\n";
            ans = ans * power(i, std::min(degA[i], degB[i])) % mod;
        }
    }*/
    //std::cout << "\n";

    std::cout << ans;
}

// 5 3 2 18
// 6 7 10 9

// 540
// 3780

// 2 2 3 3 3 5
// 2 2 3 3 3 5 7