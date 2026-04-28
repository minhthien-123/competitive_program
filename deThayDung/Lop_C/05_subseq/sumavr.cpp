#include <bits/stdc++.h>
using namespace std;

long long n, i, a[1000005], s, b[1000005];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("sumavr.inp", "r", stdin);
    freopen("sumavr.out", "w", stdout);

    cin >> n;
    b[0] = 0;
    for (i = 1; i <= n; i++){
        cin >> a[i];
    }

    b[1] = a[1];

    //for (i = 0; i < n; i++) cout << a[i] << " ";
    cout << a[1] << " ";
    s = b[1];

    for (i = 2; i <= n; i++){
        //cout << s << " ";
        //s += a[i];
        b[i] = a[i] * i - s;
        cout << b[i] << " ";
        s += b[i];
        //cout << a[i] * i - b[i];
    }

    return 0;
}
