#include <bits/stdc++.h>
using namespace std;

long long k, n, ans, i, a[1000005], gmax[1000005], gmin[1000005], mx = LLONG_MIN, mn = LLONG_MAX;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("subseq.inp", "r", stdin);
    freopen("subseq.out", "w", stdout);

    cin >> n >> k;
    a[0] = 0;
    for (i = 1; i <= n; i++){
        cin >> a[i];
        a[i] += a[i - 1];
    }

    for (i = k; i <= n; i++){
        mn = min(mn, a[i - k]);
        mx = max(mx, a[i] - mn);
    }

    cout << mx;

    return 0;
}
