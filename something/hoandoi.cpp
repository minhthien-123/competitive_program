#include <bits/stdc++.h>
using namespace std;

int n, a[1000005], b[1000005], c[1000005];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) cin >> c[i];

    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    sort(c + 1, c + n + 1);

    /*for (int i = 1; i <= n; i++) cout << a[i] << " ";
    cout << "\n";
    for (int i = 1; i <= n; i++) cout << b[i] << " ";
    cout << "\n";
    for (int i = 1; i <= n; i++) cout << c[i] << " ";
    cout << "\n";*/

    int i = 1, j = 1, k = 1, d = 0;
    while (i <= n){
        while (j <= n && b[j] <= a[i]) j++;
        if (j > n) break;
        while (k <= n && c[k] <= b[j]) k++;
        if (k > n) break;
        //cout << i << " " << j << " " << k << "\n";
        d++;
        i++;
        j++;
        k++;
    }

    cout << d;
}
