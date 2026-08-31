#include <bits/stdc++.h>
#define task "s04"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r")){
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    int n, q;
    std::cin >> n >> q;
    int a[n + 7];
    for (int i = 0; i < n; i++){
        std::cin >> a[i];
    }

    std::sort(a, a + n);

    for (int i = 0; i < q; i++){
        int l, r;
        std::cin >> l >> r;
        std::cout << std::upper_bound(a, a + n, r) - std::lower_bound(a, a + n, l) << "\n";
    }

    return 0;
}
