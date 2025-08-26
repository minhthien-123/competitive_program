#include <bits/stdc++.h>
#define task ""
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e6 + 7;

int d[maxn];
std::map<int, int> mp;

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r")){
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    int m, n;
    std::cin >> m >> n;

    if (m <= 1e5 && n <= 1e5){
        for (int i = 1; i <= m; i++){
            int x;
            std::cin >> x;
            mp[x]++;
        }

        int ans = 0;
        for (int i = 1; i <= n; i++){
            int x;
            std::cin >> x;
            if (mp[x]){
                ans++;
            }
        }

        std::cout << ans;
    }else{
        for (int i = 1; i <= m; i++){
            int x;
            std::cin >> x;
            d[x]++;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++){
            int x;
            std::cin >> x;
            if (d[x]){
                ans++;
            }
        }

        std::cout << ans;
    }

    return 0;
}

