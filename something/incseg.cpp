#include <bits/stdc++.h>
using namespace std;

int n, a[1000005], dp[1000005], mx = 0;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    //freopen("incseg.inp", "r", stdin);
    //freopen("incseg.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 1; i < n; i++) if (a[i] >= a[i - 1]){
        dp[i] = dp[i - 1] + 1;
        mx = max(mx, dp[i]);
    }

    cout << mx + 1;

    return 0;
}
