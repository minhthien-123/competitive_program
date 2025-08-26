#include <bits/stdc++.h>
#define ll long long

const ll mod = 21111983;
const ll maxn = 1e6 + 5;
ll q, n, a[maxn];

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    std::freopen("sdpri.inp", "r", stdin);
    std::freopen("sdpri.out", "w", stdout);


    for (ll i = 2; i <= maxn; i++)
        if (a[i] == 0)
            for (ll j = i; j <= maxn; j += i)
                a[j] = (a[j] + i) % mod;

    std::cin >> q;
    while(q--){
        std::cin >> n;
        std::cout << a[n] << "\n";
    }

    return 0;
}