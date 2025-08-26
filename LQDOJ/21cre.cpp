#include <bits/stdc++.h>
#define task "21cre"
#define ll long long

ll n, ans, i;
ll a[2000010];

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen(task".inp", "r", stdin);
    std::freopen(task".out", "w", stdout);

    std::cin >> n;
    if (n <= 100000){
        std::map<ll, ll> m;
        for (i = 1; i <= n; i++){
            ll x;
            std::cin >> x;
            if (m[x] == 0) ans++;
            m[x]++;
        }
    }else{
        for (i = 1; i <= n; i++){
            ll x;
            std::cin >> x;
            x += 1000000;
            if (a[x] == 0) ans++;
            a[x]++;
        }
    }

    std::cout << ans;

    return 0;
}
