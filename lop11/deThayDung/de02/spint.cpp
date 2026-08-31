#include <bits/stdc++.h>
#define ll long long

ll n, ans = 1, d = 0, a[1000005];

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    std::freopen("spint.inp", "r", stdin);
    std::freopen("spint.out", "w", stdout);

    std::cin >> n;
    for (ll i = 0, x; i < n; i++){
        std::cin >> x;
        if (x > 0){
            a[x] = 1;
            d++;
        }
    }

    for (ll i = 1; i <= 1e6; i++)
        if (a[i] == 0){
            std::cout << i;
            return 0;
        }

    return 0;
}