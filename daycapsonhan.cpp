#include <bits/stdc++.h>
using namespace std;

long long m = 1000000007;
long long n, i, j, q, a[1000005], max_len, ans[1000005];
long long dp[35][1000005];
map<int, long long> best_dp;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //freopen("daycapsonhan.inp", "r", stdin);
    //freopen("daycapsonhan.out", "w", stdout);

    cin >> n >> q;
    for (i = 1; i <= n; i++){
        cin >> a[i];
        dp[1][i] = 1;
    }

    max_len = __lg((int)1e9) + 1;
    for (i = 2; i <= max_len; i++){
        best_dp.clear();
        for (j = 1; j <= n; j++){
            if (a[j] % q == 0){
                dp[i][j] = (dp[i][j] + best_dp[a[j] / q]) % m;
            }
            ans[i] = (ans[i] + dp[i][j]) % m;
            best_dp[a[j]] = (best_dp[a[j]] + dp[i - 1][j]) % m;
        }
    }

    for (i = 2; i <= n; i++){
        if (i <= max_len) cout << ans[i] << " ";
        else              cout << 0 << " ";
    }
    return 0;
}