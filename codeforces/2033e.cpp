#include <bits/stdc++.h>
#define task "codeforces"
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

    int t;
    std::cin >> t;
    while (t--){
        int n;
        std::cin >> n;
        std::vector<int> p(n + 7);

        for (int i = 1; i <= n; i++){
            std::cin >> p[i];
        }

        std::vector<bool> vis(n + 7, 0);
        int ans = 0;

        for (int i = 1; i <= n; i++){
            if (!vis[i]){
                int tmp = 0, cur = i;

                while (!vis[cur]){
                    vis[cur] = true;
                    cur = p[cur];
                    tmp++;
                }

                if (tmp > 1){
                    ans += (tmp - 1);
                }
            }
        }

        std::cout << ans << "\n";
    }

    return 0;
}

