#include <bits/stdc++.h>
using namespace std;

long long n, x, y, i;
long long a[1000005], b[1000005], c[1000005];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("daymoi.inp", "r", stdin);
    freopen("daymoi.out", "w", stdout);

    cin >> n;
    for (i = 0; i < n; i++) cin >> a[i];
    for (i = 0; i < n; i++) cin >> b[i];

    c[0] = a[0] * b[0];
    for (i = 1; i < n; i++){
        a[i] = max(a[i], a[i - 1]);
        c[i] = max(c[i - 1], a[i] * b[i]);
    }

    for (i = 0; i < n; i++) cout << c[i] << "\n";

    return 0;
}

