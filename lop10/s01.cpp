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
    std::vector<int> a(n);
    for (int i = 0; i < n; i++){
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());

    while (q--){
        int t;
        std::cin >> t;

        if(std::binary_search(a.begin(), a.end(), t)){
            std::cout << "1\n";
        }else{
            std::cout << "0\n";
        }
    }

    return 0;
}


