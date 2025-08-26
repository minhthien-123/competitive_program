#include <bits/stdc++.h>
#define ll long long

ll n, m, a[1000005], ans = 0;
std::map<ll, ll> ma;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    std::freopen("sweet3.inp", "r", stdin);
    std::freopen("sweet3.out", "w", stdout);

    /*n = 1e5;
    m = 10;
    for (int i = 1; i <= n; i++)
        a[i] = i;*/

    std::cin >> n >> m;
    for (ll i = 1; i <= n; i++){
        std::cin >> a[i];
        a[i] %= m;
    }

    /*for (ll i = 0; i <= n; i++)
        std::cout << a[i] << " ";
    std::cout << "\n";*/

    for (ll i = 1; i <= n; i++){
        a[i] = (a[i] + a[i - 1]) % m;
    }

    /*for (ll i = 0; i <= n; i++)
        std::cout << a[i] << " ";
    std::cout << "\n";*/

    for (ll i = 0; i <= n; i++)
        ma[a[i]] ++;

    for (ll i = 0; i <= n; i++){
        ll tmp = ma[a[i]];
        ans += tmp * (tmp - 1) / 2;
        ma[a[i]] = 0;
    }

    std::cout << ans;

    return 0;
}

//4 1 5
//1 1 2
//1 2 4