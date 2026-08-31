#include <bits/stdc++.h>

#define ll long long

ll n, x, a[100005], ans = 0;
std::map<ll, ll> m;
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    std::freopen("sum13.inp", "r", stdin);
    std::freopen("sum13.out", "w", stdout);

    std::cin >> n >> x;

    a[0] = 0;
    m[0] = 1;
    for (ll i = 1, k; i <= n; i++){
        std::cin >> k;
        a[i] = a[i - 1] + k;
        m[a[i]]++;
    }

    //for (ll i = 1; i <= n; i++) std::cout << a[i] << " ";
    //std::cout << "\n";

    for (int i = 1; i <= n; i++)
        if (m[a[i] + x] > 0){
            //std::cout << i << "\n";
            ans += m[a[i]];
        }else if(a[i] == x || a[i] == -x){
            ans++;
        }

    std::cout << ans;

    return 0;
}