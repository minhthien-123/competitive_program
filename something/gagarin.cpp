#include <bits/stdc++.h>
#define ll long long

const int maxn = 1e3 + 7;

int pos[6][maxn], a[6][maxn], dp[maxn];
int n, k;

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> n >> k;
    for(int i = 1; i <= k; i++){
        for(int j = 1; j <= n; j++){
            std::cin >> a[i][j];
            pos[i][a[i][j]] = j;
        }
    }

    int ans = 1;
    dp[n] = 1;

    for(int i = n - 1; i >= 1; i--){
        dp[i] = 1;
        for(int j = i + 1; j <= n; j++){
            bool flag = true;
            for(int g = 1; g <= k; g++){
                if(pos[g][a[1][i]] > pos[g][a[1][j]]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
        ans = std::max(ans, dp[i]);
    }

    std::cout << ans;

    return 0;
}
