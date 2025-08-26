#include <bits/stdc++.h>
#define task "disnum"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen(task".inp", "r", stdin);
    std::freopen(task".out", "w", stdout);

    int n, d = 0;
    std::map<int, bool> m;
    std::cin >> n;
    while(n--){
        int t;
        std::cin >> t;
        if (!m[t])
            d++;
        m[t] = true;
    }

    std::cout << d;

    return 0;
}
