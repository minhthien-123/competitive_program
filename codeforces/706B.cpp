#include <bits/stdc++.h>
#define task "codeforces"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

bool cmp(int a, int b){
    return a <= b;
}

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    //std::freopen(task".inp", "r", stdin);
    //std::freopen(task".out", "w", stdout);

    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++){
        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end());

    /*for (int i : a){
        std::cout << i << " ";
    }
    std::cout << "\n";*/

    int q;
    std::cin >> q;
    while (q--){
        int t;
        std::cin >> t;
        auto tmp = std::upper_bound(a.begin(), a.end(), t);
        std::cout << tmp - a.begin();
        std::cout << "\n";
    }

    return 0;
}

