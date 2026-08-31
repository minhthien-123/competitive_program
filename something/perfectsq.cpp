#include <bits/stdc++.h>
#define task "perfectsq"
#define int long long

const int maxn = 1e6 + 7;

int n, g = 0, ans = LLONG_MIN, a[maxn];

bool check(int a){
    return sqrt(a) * sqrt(a) == a;
}

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen(task".inp", "r", stdin);
    std::freopen(task".out", "w", stdout);

    std::cin >> n;
    for (int i = 1; i <= n; i++){
        std::cin >> a[i];
        if (g == 0) g = a[i];
        else        g = std::__gcd(g, a[i]);
    }

    for (int i = 1; i <= sqrt(g); i++)
        if (g % i == 0){
            if (check(i) && i != 1) ans = std::max(ans, i);
            if (check(g / i) && (g / i) != 1) ans = std::max(ans, g / i);
        }

    std::cout << ans;

    return 0;
}
