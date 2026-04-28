#include <bits/stdc++.h>
#define ll long long

ll n, d, a[1000005], l, r, k;

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen("growing3.inp", "r", stdin);
    std::freopen("growing3.out", "w", stdout);

    std::cin >> n >> d;
    while (d--){
        std::cin >> l >> r >> k;
        a[l] += k;
        a[l + 1] -= k - 1;
        a[r + 1] -= k + r - l + 1;
        a[r + 2] += k + r - l;
    }

    for (ll i = 1; i <= n; i++) a[i] = a[i - 1] + a[i];
    for (ll i = 1; i <= n; i++) a[i] = a[i - 1] + a[i];

    for (ll i = 1; i <= n; i++) std::cout << a[i] << " ";
}

