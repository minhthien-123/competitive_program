#include <bits/stdc++h>
#define ll long long

const ll maxn = 1e7;
const ll maxx = 5e5 + 9;
const ll mod  = 1e9 + 7;

int main(){
    for (ll i = 2; i * i <= maxn; ++i) {
        if (minPrime[i] == 0) {
            for (ll j = i * i; j <= maxn; j += i) {
                if (minPrime[j] == 0) {
                    minPrime[j] = i;
                }
            }
        }
    }

    std::cin >> n;

    for (int i = 1; i <= n; i++)
        std::cin >> a[i];


}