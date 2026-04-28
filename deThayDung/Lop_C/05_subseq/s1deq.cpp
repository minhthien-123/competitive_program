#include <bits/stdc++.h>
using namespace std;

long long n, i, mx = LLONG_MIN, s = 0, a[1000005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    freopen("s1deq.inp", "r", stdin);
    freopen("s1deq.out", "w", stdout);

    cin >> n;

    for (i = 0; i < n; i++) cin >> a[i];

    s = 0;
    for (i = 0; i < n; i++){
        s = max(s + a[i], a[i]);
        mx = max(mx, s);
    }

    cout << mx;

    return 0;
}