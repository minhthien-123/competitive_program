#include <bits/stdc++.h>
#define task "sdivk"
#define ll long long

const ll maxn = 1e6 + 7;

ll n, k, i;
ll a[maxn], d[maxn], ans;

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen(task".inp", "r", stdin);
    std::freopen(task".out", "w", stdout);

    d[0] = 1;
    std::cin >> n >> k;
    for (i = 1; i <= n; i++){
        std::cin >> a[i];
        a[i] = (a[i] + a[i - 1]) % k;
        d[a[i]]++;
    }

    for (i = 0; i < k; i++){
        ll tmp = d[i];
        ans += tmp * (tmp - 1) / 2;
    }

    std::cout << ans;

    return 0;
}
