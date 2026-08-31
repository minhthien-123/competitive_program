#include <bits/stdc++.h>
#define task ""
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

const int mod = 1e9 + 7;
const int maxn = 1e3 + 7;

int n, m, dp[maxn][maxn];
char a[maxn][maxn];
signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    //std::freopen(task".inp", "r", stdin);
    //std::freopen(task".out", "w", stdout);

    std::cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            std::cin >> a[i][j];

    dp[1][1] = 1;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(a[i][j] == '.'){
                if(a[i - 1][j] == '.'){
                    dp[i][j] += dp[i - 1][j];
                    dp[i][j] %= mod;
                }
                if(a[i][j - 1]=='.'){
                    dp[i][j] += dp[i][j-1];
                    dp[i][j] %= mod;
                }
            }

    /*for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)
            std::cout << a[i][j] << ' ';
        std::cout << "\n";
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)
            std::cout << dp[i][j] << ' ';
        std::cout << "\n";
    }*/

    std::cout << dp[n][m];
    return 0;
}