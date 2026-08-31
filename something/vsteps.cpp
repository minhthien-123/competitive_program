#include <bits/stdc++.h>
using namespace std;

unsigned long long dp[1000005], a[1000005];
long long n, k, i;
bool kt;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //freopen("vsteps.inp", "r", stdin);
    //freopen("vsteps.out", "w", stdout);

    cin >> n >> k;
    for (i = 0; i < k; i++){
        cin >> a[i];
        //if (i != 0 && a[i] - a[i - 1] == 1) kt = false;
    }

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for (i = 3; i <= n; i++)
        dp[i] = (dp[i - 1] + dp[i - 2]) % 14062008;

    /*for (i = 0; i < n; i++) if (dp[i] < 0){
        cout << i;
        break;
    }*/

    cout << dp[n];
}
