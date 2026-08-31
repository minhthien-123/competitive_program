#include <bits/stdc++.h>
using namespace std;

long long n, a[1000005], flag, d, ans = LLONG_MIN;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("spec.inp", "r", stdin);
    freopen("spec.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    if (a[1] > 0) flag = 1;
    else          flag = -1;

    for (int i = 1; i <= n; i++){
        if (a[i] * flag >= 0) d++;
        else{
            ans = max(ans, d);
            flag *= -1;
            d = 1;
        }
    }

    cout << max(d, ans);
}
