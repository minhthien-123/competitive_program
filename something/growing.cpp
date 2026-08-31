#include <bits/stdc++.h>
using namespace std;

long long n, d, l, r, k;
long long a[1000005];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("growing.inp", "r", stdin);
    freopen("growing.out", "w", stdout);

    cin >> n >> d;
    a[0] = 0;

    while(d--){
        cin >> l >> r >> k;
        a[l] += k;
        a[r + 1] -= k;
    }

    for (long long i = 1; i <= n; i++) a[i] += a[i - 1];

    for (long long i = 1; i <= n; i++) cout << a[i] << " ";

    return 0;
}
