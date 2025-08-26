#include <bits/stdc++.h>
using namespace std;

int n, i, j, res, ans, t;
int a[1000005];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdout);

    cin >> t;
    while (t--){
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];

        ans = INT_MIN;
        res = INT_MIN;

        for (int i = 1; i < n; i++){
            for (int j = i + 1; j <= n; j++){
                ans = max(ans, __gcd(a[i], a[j]));
            }
        }

        //cout << ans << " ";

        for (int i = 1; i < n; i++){
            for (int j = i + 1; j <= n; j++){
                if (__gcd(a[i], a[j]) != ans){
                    res = max(res, __gcd(a[i], a[j]));
                }
            }
        }

        if (res == INT_MIN) res = 1;

        cout << res << "\n";

        for (int i = 1; i <= n; i++) a[i] = 0;
    }
}
