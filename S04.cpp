#include <bits/stdc++.h>
using namespace std;

long long n, q, l, r, x, s, i, j, a[10005];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("S04.inp", "r", stdin);
    freopen("S04.out", "w", stdout);

    cin >> n >> q;
    for (i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a, a + n);

    for (i = 0; i < q; i++){
        cin >> l >> r;
        cout << upper_bound(a, a + n, r) - lower_bound(a, a + n, l) << "\n";
    }


    return 0;
}
