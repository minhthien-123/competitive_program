#include <bits/stdc++.h>
#define task "hq"
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
    std::set<int> s;
    for (int i = 1; i <= n; i++){
        int x;
        std::cin >> x;
        auto tmp = s.lower_bound(x);
        if (tmp != s.begin()){
            tmp--;
            std::cout << *tmp;
        }else{
            std::cout << -1;
        }
        s.ins(x);
        std::cout << "\n";
    }

    return 0;
}

