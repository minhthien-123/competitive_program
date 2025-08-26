#include <bits/stdc++.h>
#define task "s02"
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
    int a[n + 1];
    for (int i = 1; i <= n; i++){
        std::cin >> a[i];
    }
    std::sort(a + 1, a + n + 1);

    for (int i = 1; i <= q; i++){
        int t;
        std::cin >> t;
        int *tmp = std::lower_bound(a + 1, a + n + 1, t);
        if (tmp != (a + n + 1)){
            std::cout << *tmp << "\n";
        }else{
            std::cout << "NO\n";
        }
    }

    return 0;
}


