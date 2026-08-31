#include <bits/stdc++.h>
#define task "bs02"
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

    int n, m;
    std::map<int, int> mp;
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++){
        int x;
        std::cin >> x;
        if (mp[x] == 0){
            mp[x] = i;
        }
    }

    for (int i = 1; i <= m; i++){
        int x;
        std::cin >> x;
        std::cout << mp[x] << ' ';
    }

    return 0;
}

