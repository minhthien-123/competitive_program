#include <bits/stdc++.h>
#define task "exp"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

int n, k, a, ans = LLONG_MAX, res, tmp, t;

void existence(int x, int n){
    if (x > n) return;
    res += trunc(n / x);
    existence(x * tmp, n);
}

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    //std::freopen(task".inp", "r", stdin);
    //std::freopen(task".out", "w", stdout);

    std::cin >> t;
    while (t--){
        std::cin >> n >> k;

        int tmp = k, cmp = k;
        ans = 0;
        while (tmp <= n){
            ans += n / tmp;
            tmp *= cmp;
        }

        std::cout << ans << "\n";
    }

    return 0;
}
