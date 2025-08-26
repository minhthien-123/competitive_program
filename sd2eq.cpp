#include <bits/stdc++.h>
using namespace std;

long long n, i, x, k, s, a[1000005], arr[1000005], prf[1000005], ans = LLONG_MIN, sum, d;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //freopen("sd2eq.inp", "r", stdin);
    //freopen("sd2eq.out", "w", stdout);

    //cout << ans;

    cin >> n;
    for (i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
        if (a[i] > 0) d ++;
    }

    if (d == n) cout << sum;

    else if (n == 2) cout << a[0] + a[1];

    else{
        s = 0;
        prf[0] = a[0];
        for (i = 1; i < n; i++){
            s = max(s + a[i], a[i]);
            prf[i] = max(prf[i - 1], s);
        }

        s = 0;
        arr[n - 1] = a[n - 1];
        for (i = n - 2; i >= 0; i--){
            s = max(s + a[i], a[i]);
            arr[i] = max(arr[i + 1], s);
        }

        for (i = 0; i < n; i++) cout << prf[i] << " ";
        cout << "\n";
        for (i = 0; i < n; i++) cout << arr[i] << " ";
        cout << "\n";

        for (i = 1; i < n; i++) ans = max(ans, arr[i] + prf[i - 1]);

        cout << ans;
    }

    return 0;
}
