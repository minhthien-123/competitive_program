#include <bits/stdc++.h>
using namespace std;

int n, a[505][505];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("vboard.inp", "r", stdin);
    freopen("vboard.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
            if ((i - j) % 2 != 0) a[i][j] = 0 - a[i][j];
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
        }
    }

    /*for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cout << a[i][j] << " ";
        }cout << "\n";
    }*/

    int q;
    cin >> q;
    while(q--){
        int i1, j1, i2, j2;
        cin >> i1 >> j1 >> i2 >> j2;
        cout << abs(a[i2][j2] - a[i2][j1 - 1] - a[i1 - 1][j2] + a[i1 - 1][j1 - 1]) << "\n";
    }
}
