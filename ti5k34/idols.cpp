#include <bits/stdc++.h>
#define task "idols"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e6 + 7;
int a[maxn];

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    //std::freopen(task".inp", "r", stdin);
    //std::freopen(task".out", "w", stdout);

    int n;
    int ans = LLONG_MIN;
    std::cin >> n;
    for (int i = 1; i <= n; i++){
        int k;
        std::cin >> k;
        for (int j = 1; j <= k; j++){
            int x;
            std::cin >> x;
            a[x]++;
            ans = std::max(ans, a[x]);
        }
    }

    for (int i = 1; i <= 1000000; i++){
        if (a[i] == ans){
            std::cout << i << " ";
        }
    }

    //std::cout << ans;

    return 0;
}

