#include <bits/stdc++.h>
#define task ""
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

const int maxn = 3e3 + 7;

double dp[maxn], ngua[maxn], sap[maxn];
int n;
double ans = 0;

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    //std::freopen(task".inp", "r", stdin);
    //std::freopen(task".out", "w", stdout);

    std::cin >> n;
    for(int i = 1; i <= n; i++){
        std::cin >> ngua[i];
        sap[i] = 1 - ngua[i];
    }

    memset(dp, 0, sizeof dp);
    dp[0] = 1;

    for(int i = 1; i <= n; i++)
        for(int j = i; j >= 0; j--)
            if(j > 0)
                dp[j] = dp[j] * sap[i] + dp[j - 1] * ngua[i];
            else 
                dp[j] = dp[j] * sap[i];

    for(int i = ((n - 1) / 2) + 1;i <= n; i++) ans += dp[i];

    std::cout << std::setprecision(10) << std::fixed << ans;
}
