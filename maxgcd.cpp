#include <bits/stdc++.h>
using namespace std;

long long n, k, i, l, mid, ans = 1, r = LLONG_MAX;
long long a[1000005];

bool check(long long m){
    long long s = 0;
    for (i = 1; i <= n; i++) s += m * (a[i] / m + 1) - a[i];

    //cout << m << " " << s << "\n";

    if (s <= k) return true;
    else        return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //freopen("maxgcd.inp", "r", stdin);
    //freopen("maxgcd.out", "w", stdout);

    cin >> n >> k;
    for (i = 1; i <= n; i++){
        cin >> a[i];
        r = min(r, a[i] + k);
    }

    l = 2;
    while (l <= r){
        mid = (l + r) / 2;
        if (check(mid)){
            l = mid + 1;
            ans = mid;
        }else r = mid - 1;
    }

    cout << ans;
    //cout << check(5);

    return 0;
}
