#include <bits/stdc++.h>
#define ll long long

/*ll powerr(ll a, ll b, ll m) {
    ll result = 1;
    for(int i = 1; i <= b; i++) {
        result *= a;
        result %= m;
    }
    return result;
}*/

ll power(ll a, ll b, ll m){
    if (b == 0) return 1 % m;
    else{
        ll tmp = power(a, b / 2, m);
        if (b % 2 == 0)
            return tmp * tmp % m;
        else
            return a * (tmp * tmp % m) % m;
    }
}

ll x, n, m;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    std::freopen("power5.inp", "r", stdin);
    std::freopen("power5.out", "w", stdout);

    std::cin >> x >> n >> m;

    //std::cout << powerr(x, n, m) << "\n";
    std::cout << power(x, n, m);

    return 0;
}