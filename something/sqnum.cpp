#include <bits/stdc++.h>

#define ll long long
inline is_square(ll a) return (a == sqrt(a) * sqrt(a));

ll n, i;



ll count(ll x){
    ll ans = 0;

    for (i = 1; i <= sqrt(n); i++){
        if (is_square(i)){

        }
    }

    return ans;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    std::cin >> n;
    std::cout << count(n);

    return 0;
}