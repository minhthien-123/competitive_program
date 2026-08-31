#include <bits/stdc++.h>
#define task "stat"
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

    int n;
    std::cin >> n;
    int a[n + 1], b[n + 1];

    for (int i = 0; i < n; i++){
        std::cin >> a[i];
        b[i] = a[i];
    }

    std::sort(b, b + n);

    for (int i = 0; i < n; i++){
        int tmp = a[i];
        std::cout << std::lower_bound(b, b + n, tmp) - b << " " << n - (std::upper_bound(b, b + n, tmp) - b) << "\n";
    }

    return 0;
}

