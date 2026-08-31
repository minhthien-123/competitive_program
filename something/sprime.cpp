#include <bits/stdc++.h>
using namespace std;

bool a[5736401];
long long i, j, n, s = 0;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("sprime.inp", "r", stdin);
    freopen("sprime.out", "w", stdout);

    cin >> n;

    for (i = 0; i <= 5736401; i++){
        a[i] = true;
    }

    a[0] = false;
    a[1] = false;
    for (i = 2; i * i <= 5736401; i++){
        if (a[i]){
            for (j = i * i; j <= 5736401; j += i){
                a[j] = false;
            }
        }
    }

    for (i = 0; i <= n; i++)if (a[i] == true) s += i;

    //for (i = 0; i <= s; i++) cout << a[i] << " ";
    //cout << "\n";

    cout << s << "\n";
    if (a[s] == true) cout << "YES";
    else              cout << "NO";
}
