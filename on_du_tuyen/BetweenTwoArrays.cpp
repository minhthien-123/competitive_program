#include <bits/stdc++.h>
#define task "BetweenTwoArrays"
#define int long long

const int mod = 998244353;
const int maxn = 3e3 + 7;
int n, a[maxn], b[maxn], ans, dp[maxn][maxn], sum[maxn][maxn];

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    //std::freopen(task".inp", "r", stdin);
    //std::freopen(task".out", "w", stdout);

    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];
    for (int i = 1; i <= n; i++)
        std::cin >> b[i];

    for (int i = a[1]; i <= b[1]; i++)
        dp[1][i]  = 1;

    for (int i = 2; i <= n; i++){
        int res = 0;
        for (int j = 0; j <= b[i]; j++){
            res = (res + dp[i - 1][j]) % mod;
            if (j >= a[i])
                dp[i][j] = res;
        }
    }

    int ans = 0;
    for (int i = a[n]; i <= b[n]; i++)
        ans = (ans + dp[n][i]) % mod;

    std::cout << ans;

    return 0;
}
