#include <bits/stdc++.h>
using namespace std;

long long n, i, j, a[1005], b[1005];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //freopen("inversion.inp", "r", stdin);
    //freopen("inversion.out", "w", stdout);

    cin >> n;
    for (i = 0; i < n; i++){
        cin >> a[i];
        for (j = i; j >= 0; j--) if (a[j] > a[i]) b[i]++;
    }

    //for (i = 0; i < n; i++) cout << b[i] << " ";
    //cout << "\n";

    for (i = 0; i < n; i++){
        j = 0;
        while (j < n && a[j] != i + 1) j++;
        //cout << j;
        cout << b[j] << " ";

    }

    return 0;
}
