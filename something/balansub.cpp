#include <bits/stdc++.h>
using namespace std;

long long n, i, mx = LLONG_MIN;
long long a[1000005];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("balansub.inp", "r", stdin);
    freopen("balansub.out", "w", stdout);

    cin >> n;
    a[0] = 0;
    for (i = 1; i <= n; i++){
        cin >> a[i];
        if (a[i] > a[i - 1]) a[i] = a[i - 1] + 1;
    }

    for (i = 1; i <= n; i++) mx = max(a[i], mx);

    cout << mx;
}
