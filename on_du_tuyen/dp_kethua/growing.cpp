#include <bits/stdc++.h>
#define task "growing"
#define ll long long

ll n, d, a[1000005];

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    //std::freopen(task".inp", "r", stdin);
    //std::freopen(task".out", "w", stdout);

    std::cin >> n >> d;
    while(d--){
        ll l, r, k;
        std::cin >> l >> r >> k;
        a[l] += k;
        a[r + 1] -= k;
    }

    for (ll i = 1; i <= n; i++)
        a[i] += a[i - 1];

    for (ll i = 1; i <= n; i++)
        std::cout << a[i] << " ";

    return 0;
}
