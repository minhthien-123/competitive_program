#include <bits/stdc++.h>
using namespace std;

long double x, y, n, i, s;

long double sum(long double n){
    return n * (n + 1) / 2;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("sum6x.inp", "r", stdin);
    freopen("sum6x.out", "w", stdout);

    cin >> n >> x;
    y = x;
    for (i = 1; i <= n; i++){
        //cout << sum(i) << "\n";
        s += x / sum(i);
        x *= y;
    }

    cout << fixed << setprecision(6) << s;

    return 0;

}

