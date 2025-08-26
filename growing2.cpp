#include <bits/stdc++.h>
using namespace std;

long long n, m, d, l, r, u, v, k;
long long a[5005][5005], s[5005][5005];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //freopen("growing2.inp", "r", stdin);
    //freopen("growing2.out", "w", stdout);

    cin >> n >> m >> d;
    while (d--){
        cin >> l >> r >> u >> v >> k;
        a[l][u] += k;
        a[l][v + 1] -= k;
        a[r + 1][u] -= k;
        a[r + 1][v + 1] += k;
    }

    for (long long i = 1; i <= n; i++){
        for (long long j = 1; j <= m; j++){
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
        }
    }

    for (long long i = 1; i <= n; i++){
        for (long long j = 1; j <= m; j++){
            cout << s[i][j] << " ";
        }

        cout << "\n";
    }
}
