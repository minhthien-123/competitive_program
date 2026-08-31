#include <bits/stdc++.h>
#define ll long long

const int maxn = 1e6 + 7;

bool isPrime(int x){
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return false;
    return true;
}

ll n, ans;
bool a[maxn];

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen("18com.inp", "r", stdin);
    std::freopen("18com.out", "w", stdout);

    std::cin >> n;
    if (n <= 1000){
        for (ll i = 1, x; i <= n; i++){
            std::cin >> x;
            if (!isPrime(x))
                ans += x;
        }
    }else{
        for (ll i = 0; i <= maxn; i++)
            a[i] = true;

        a[0] = false;
        a[1] = false;
        for (ll i = 2; i * i <= maxn; i++){
            if (a[i]){
                for (ll j = i * i; j <= maxn; j += i){
                    a[j] = false;
                }
            }
        }

        for (ll i = 1, x; i <= n; i++){
            std::cin >> x;
            if (x > 2)
                if (!a[x])
                    ans += x;
        }
    }

    std::cout << ans;

    return 0;
}
