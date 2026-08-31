#include <bits/stdc++.h>
using namespace std;

long long n, i, j, k, q;
long long a[1000005], b[1000005];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("udm.inp", "r", stdin);
    freopen("udm.out", "w", stdout);

    cin >> n >> q;
    while (q--){
        cin >> i >> j >> k;
        a[i] += k;
        a[i + 1] -= k - 1;
        a[j + 1] -= k + j - i + 1;
        a[j + 2] += k + j - i;
    }

    a[0] = 0;
    for (i = 1; i <= n; i++) a[i] = a[i - 1] + a[i];
    for (i = 1; i <= n; i++) a[i] = a[i - 1] + a[i];

    for (i = 1; i <= n; i++) cout << a[i] << " ";

}
