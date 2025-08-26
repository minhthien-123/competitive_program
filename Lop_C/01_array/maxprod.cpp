#include <bits/stdc++.h>
using namespace std;

long long n, i, a[1000005], mx = LLONG_MIN, mn = LLONG_MAX, smax = LLONG_MIN, sm, smin = LLONG_MAX, max_dex = 0, min_dex = 0;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("maxprod.inp", "r", stdin);
    freopen("maxprod.out", "w", stdout);

    cin >> n;
    for (i = 0; i < n; i++){
        cin >> a[i];
        //mx = max(a[i], mx);
        //mn = min(a[i], mn);
        if (a[i] >= mx){
            mx = a[i];
            max_dex = i;
        }
        if (a[i] <= mn){
            mn = a[i];
            min_dex = i;
        }
    }

    if (n == 2) cout << a[0] * a[1];
    else if (n == 3) cout << max(a[0] * a[1], max(a[1] * a[2], a[2] * a[0]));
    else{
        for (i = 0; i < n; i++){
            if (i != max_dex) smax = max(smax, a[i]);
            if (i != min_dex) smin = min(smin, a[i]);
        }

        //cout << mx << " " << smax << " " << max_dex << "\n";
        //cout << mn << " " << smin << " " << min_dex << "\n";

        cout << max(mx * smax, mn * smin);
    }
}