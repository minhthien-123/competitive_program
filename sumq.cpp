#include <bits/stdc++.h>
using namespace std;

long long n, i, t ,j, l, r;
long long a[1000005], m1[1000005], m2[1000005];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("sumq.inp", "r", stdin);
    freopen("sumq.out", "w", stdout);

    cin >> n >> t;
    a[0] = 0;
    for (i = 1; i <= n; i++){
        cin >> a[i];
        a[i] = a[i - 1] + a[i];
    }

    m1[0] = 0;
    m2[n + 1] = LLONG_MIN;

    for (i = 1; i <= n; i++) m1[i] = min(m1[i - 1], a[i]);

    for (i = n; i > 0; i--)  m2[i] = max(m2[i + 1], a[i]);

    for (i = 1; i <= n; i++) cout << m1[i] << " ";
    cout << "\n";
    for (i = 1; i <= n; i++) cout << m2[i] << " ";
    cout << "\n";

    for (j = 1; j <= t; j++){
        cin >> l >> r;
        cout << m2[r] - m1[l - 1] << "\n";
    }
}
