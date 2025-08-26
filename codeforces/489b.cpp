#include <bits/stdc++.h>
#define task ""
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
    std::cin >> n;
    int a[n + 7];
    for (int i = 1; i <= n; i++){
        std::cin >> a[i];
    }
    std::cin >> m;
    int b[m + 7];
    std::map<int, int> mp;

    for (int i = 1; i <= m; i++){
        std::cin >> b[i];
        mp[b[i]]++;
    }

    int ans = 0;
    std::sort(a + 1, a + n + 1);
    std::sort(b + 1, b + m + 1);

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (mp[b[j]] < 1){
                continue;
            }
            if (abs(a[i] - b[j]) <= 1){
                ans++;
                mp[b[j]]--;
                break;
            }
        }
    }

    std::cout << ans << "\n";

    return 0;
}
