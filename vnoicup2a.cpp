#include <bits/stdc++.h>
using namespace std;

bool kt;
char a[505][505];
int n, m;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }

    for (int i = 1; i < n; i++){
        for (int j = 1; j < m; j++){
            if (a[i][j] != a[i + 1][j] && a[i][j] != a[i][j + 1] && a[i + 1][j] != a[i + 1][j + 1] && a[i][j + 1] == a[i + 1][j + 1]){
                kt = true;
            }
        }
    }

    if (kt) cout << "YES";
    else    cout << "NO";
}
