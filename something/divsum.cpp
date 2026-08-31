#include <bits/stdc++.h>
#define ll long long

const ll maxn = 1e5;

int main(){
    ll div[maxn + 5];
    for (ll i = 1; i <= maxn; i++)
        div[i] = -i;
    for (ll i = 1; i <= maxn; i++)
        for (ll j = i; j <= maxn; j += i)
            div[j] += i;

    ll q;
    std::cin >> q;
    while (q--){
        ll x;
        std::cin >> x;
        std::cout << div[x] << "\n";
    }
}
