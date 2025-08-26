#include <bits/stdc++.h>
#define ll long long

const ll maxn = 1e7;
const ll maxx = 5e5 + 9;
const ll mod  = 1e9 + 7;
ll m, n, a[maxx], b[maxx], minPrime[maxn], degA[maxn], degB[maxn];
long long ans = 1;

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    //std::freopen("23thtbgb4c2.inp", "r", stdin);
    //std::freopen("23thtbgb4c2.out", "w", stdout)

    std::cin >> n >> m;
    for (ll i = 1; i <= n; i++) std::cin >> a[i];
    for (ll i = 1; i <= m; i++) std::cin >> b[i];

    for (ll i = 1; i <= n; i++) sieveA(a[i]);
    for (ll i = 1; i <= m; i++) sieveB(b[i]);

    for (ll i = 1; i < maxn; i++){
        if (degA[i] != 0 && degB[i] != 0){
            ans = ans * power(i, std::min(degA[i], degB[i])) % mod;
        }
    }

    std::cout << ans;
}