#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int a[105][105];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;
    while (k--){
        int x, y, u, v, c;
        cin >> x >> y >> u >> v >> c;
        for (int i = x; i <= u; i++){
            for (int j = y; j <= v; j++){
                a[i][j] = c;
            }
        }
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }

}
