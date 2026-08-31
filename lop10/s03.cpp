#include <bits/stdc++.h>
#define task "s03"
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
    std::map<int, int> m;
    for (int i = 0; i < n; i++){
        int t;
        std::cin >> t;
        m[t]++;
    }

    while (q--){
        int x;
        std::cin >> x;
        if (m[x]!=0){
            std::cout << m[x] << "\n";
        }else{
            std::cout << "NO\n";
        }
    }

    return 0;
}
