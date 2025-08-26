#include <bits/stdc++.h>
using namespace std;

long long i, n, x, a[1000005];
bool flag = true;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("perchk.inp", "r", stdin);
    freopen("perchk.out", "w", stdout);

    cin >> n;

    //cout << n << "\n";
    for (i = 0; i < n; i++){
        cin >> x;
        //cout << "x";

        if (x > 1000000)      flag = false;
        else if (x < 0)       flag = false;
        else if (a[x] == 1)   flag = false;
        if (x < 1000000) a[x]++;
        //cout << x << " " << m[x] << "\n";
    }

    //cout << "\n";

    if (flag) cout << "YES";
    else      cout << "NO";

}