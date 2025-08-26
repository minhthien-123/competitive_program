#include <bits/stdc++.h>
#define ll long long

const ll maxn = 153;

ll sum(ll x){
    ll ans = 0;
    while (x > 0){
        ans += x % 10;
        x /= 10;
    }

    return ans;
}

bool isSquare(ll x){
    ll x1 = sqrt(x);
    return x1 * x1 == x;
}

ll c;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    std::freopen("slq.inp", "r", stdin);
    std::freopen("slq.out", "w", stdout);

    std::cin >> c;
    for (ll b = 1; b <= maxn; b++){
        ll del = b * b + 4 * c;
        if (isSquare(del)){
            ll tmp = -b + (long long)sqrt(del);
            if (tmp % 2 == 0){
                tmp = tmp / 2;
                if (sum(tmp) == b){
                    std::cout << tmp;
                    return 0;
                }
            }
        }
    }

    std::cout << -1;

    return 0;
}