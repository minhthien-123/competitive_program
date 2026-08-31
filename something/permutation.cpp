#include <bits/stdc++.h>
using namespace std;

long long n, i, j, d, a[5005], b[5005], k;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("permutation.inp", "r", stdin);
    freopen("permutation.out", "w", stdout);

    cin >> n;
    for (i = 1; i <= n; i++) cin >> a[i];

    //for (i = 1; i <= n; i++) cout << b[i] << " ";
    //cout << "\n";

    for (i = 1; i <= n; i++){
        //j = 1;
        d = 0;

        /*while (d < a[i]){
            if (b[j] == 0) d++;
            cout << d << " " << j << " " << b[j] << "\n";
            //cout << j << " ";
            if (d != a[i]) j++;
            //cout << b[j] << "\n";
            //cout << j << "\n";
            //cout << a[i] << " " << j << " " << d << "\n";
        }

        //cout << d - a[i] - 1;

        //cout << a[i] << " " << j << "\n";
        b[j] = i;
        //cout << d << " " << j << "\n";*/

        for (j = 1; j <= n; j++){
            if (b[j] == 0) d++;
            if (d == (a[i] + 1)){
                b[j] = i;
                break;
            }

            // << d << " " << j << " " << b[j] << "\n";
        }

        //for (k = 1; k <= n; k++) cout << b[k] << " ";
        //cout << "\n";
    }

    for (i = 1; i <= n; i++) cout << b[i] << " ";

    return 0;
}
