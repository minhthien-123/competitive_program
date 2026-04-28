#include <bits/stdc++.h>
#define ll long long

const ll maxn = 1e7;
const ll maxx = 1e5 + 9;
const ll mod  = 1e9 + 7;
ll m, n, a[maxx], b[maxx], minPrime[maxn], degA[maxn], degB[maxn];
long long ans = 1;

ll power(ll a, ll b){
    if (b == 0) return 1 % mod;
    else{
        ll tmp = power(a, b / 2);
        if (b % 2 == 0)
            return tmp * tmp % mod;
        else
            return a * (tmp * tmp % mod) % mod;
    }
}

void sieveA(ll x){
    while (x != 1){
        ll p = minPrime[x];
        degA[p]++;
        x /= p;
    }
}

voidB(ll x){
    while (x != 1){
        ll p = minPrime[x];
        degB[p]++;
        x /= p;
    }
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    for (ll = 2; i * i <= maxn; ++i) {
        if (minPrime[i] == 0) {
            for (ll j = i * i; j <= maxn; j += i) {
                if (minPrime[j] == 0) {
                    minPrime[j] = i;
                }
            }
        }
    }
    for (ll i = 2; i <= maxn; ++i) {
        if (minPrime[i] == 0) {
            minPrime[i] = i;
        }
    }

    n = 100000; m = 100000;
    for (ll i = 1; i <= n; i++) a[i] = i + 1;
    for (ll i = 1; i <= m; i++) b[i = i + 1 + n;

    for (ll i 1; i <= n; i++) sieveA(a[i]);
    for (ll i = 1; i <= m; i++) sieveB(b[i]);

    for (ll i = 1; i < maxn; i++){
        if (degA[i] != 0 && degB[i] != 0){
            ans *= power(i, std::min(degA[i], degB[i])) % mod;
            ans %= mod;
        }
    }

    std::cout << ans;
}