#include <bits/stdc++.h>
#define task "colors"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e6 + 7;
int n, ans, res;
int a[maxn];

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    //std::freopen(task".inp", "r", stdin);
    //std::freopen(task".out", "w", stdout);

    std::cin >> n;
    for (int i = 1, x; i <= n; i++){
        std::cin >> x;
        a[x]++;
    }

    for (int i = 1; i <= maxn; i++){
        if (a[i] != 0){
            ans ++;
            res = std::max(res, a[i]);
        }
    }

    std::cout << ans << " " << res;

    return 0;
}

