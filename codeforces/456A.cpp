#include <bits/stdc++.h>
#define task "codeforces"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r")) {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    int n;
    std::cin >> n;
    ii a[n + 7];
    for (int i = 1; i <= n; i++){
        std::cin >> a[i].fi >> a[i].se;
    }

    std::sort(a + 1, a + n + 1);

    for (int i = 1; i < n; i++){
        if (a[i].se > a[i + 1].se){
            std::cout << "Happy Alex";
            return 0;
        }
    }

    std::cout << "Poor Alex";

    return 0;
}
