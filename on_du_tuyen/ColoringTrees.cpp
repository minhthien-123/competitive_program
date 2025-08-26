#include <bits/stdc++.h>
#define ll long long

const int maxn = 1e2 + 7;
const ll inf  = 1e18 + 7;
int n, m, k, p[maxn][maxn], a[maxn], tmp;
ll dp[maxn][maxn][maxn], ans = inf;

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            std::cin >> p[i][j];

    memset(dp, maxn, sizeof(dp));

    if (a[1] != 0) dp[1][a[1]][1] = 0;
    else
        for (int i = 1; i <= m; i++)
            dp[1][i][1] = p[1][i];

    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= m; j++)
            for (int u = 1; u <= k; u++)
                if (dp[i - 1][j][u] < inf)
                    if (a[i] != 0){
                        if (a[i] != j)
                            tmp = 1;
                        else
                            tmp = 0;
                        dp[i][a[i]][u + tmp] = std::min(dp[i][a[i]][u + tmp], dp[i - 1][j][u]);
                    }else
                        for (int v = 1; v <= m; v++){
                            if (v != j)
                                tmp = 1;
                            else
                                tmp = 0;
                            dp[i][v][u + tmp] = std::min(dp[i][v][u + tmp], dp[i - 1][j][u] + p[i][v]);
                        }

    for (int i = 1; i <= m; i++)
        ans = std::min(ans, dp[n][i][k]);
    if (ans == inf) ans = -1;

    std::cout << ans;

    return 0;
}
