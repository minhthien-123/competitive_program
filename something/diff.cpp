#include <bits/stdc++.h>
using namespace std;

long long n, a[1000005], b[1000005], c[1000005], ans = LLONG_MIN;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("diff.inp", "r", stdin);
    freopen("diff.out", "w", stdout);

    cin >> n;
    for (long long i = 1; i <= n; i++) cin >> a[i];

    for (long long i = 1; i <= n; i++){
        //b[i] = LLONG_MIN;
        c[i] = LLONG_MAX;
    }

    //b[1] = a[1];
    //for (long long i = 2; i <= n; i++) b[i] = max(a[i], b[i - 1]);

    c[1] = a[1];
    for (long long i = 2; i <= n; i++) c[i] = min(a[i], c[i - 1]);

    for (long long i = 1; i <= n; i++){
        ans = max(ans, a[i] - c[i]);
        //cout << a[i] << " " << c[i] << "\n";
    }

    cout << ans;
}
