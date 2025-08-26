#include <bits/stdc++.h>
using namespace std;

int n, k, a[1000005], ans[1000005], res, sum;

void Try(int i){
    for (int j = 1; j <= n; j++){
        if (j - ans[i - 1] <= 2 && j - ans[i - 1] >= 1){
            ans[i] = j;

            if (i == k){
                for (int m = 1; m <= k; m++) sum += a[ans[m]];
                //cout << "\n";
                //cout << sum << "\n";
                res = max(res, sum);

                //cout << res << " ";

                sum = 0;

                //cout << res << "\n";
            }else        Try(i + 1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //freopen("doexam.inp", "r", stdin);
    //freopen("doexam.out", "w", stdout);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];

    Try(1);
    cout << res;
}
