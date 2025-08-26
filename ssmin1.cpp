#include <bits/stdc++.h>
using namespace std;

long long n, s, a[1000005], i, mn = LLONG_MAX;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("ssmin1.inp", "r", stdin);
    freopen("ssmin1.out", "w", stdout);

    cin >> n;
    for (i = 0; i < n; i++) cin >> a[i];

    s = 0;
    for (i = 0; i < n; i++){
        s = min(s + a[i], a[i]);
        mn = min(mn, s);
    }

    cout << mn;

    return 0;

}
