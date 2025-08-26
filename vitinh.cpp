#include <bits/stdc++.h>
using namespace std;

long double n, i, s;

long long ds(long long n){
    long long d = 0;
    while(n >= 10){
        n /= 10;
        d++;
    }
    return d;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("vitinh.inp", "r", stdin);
    freopen("vitinh.out", "w", stdout);

    cin >> n;
    /*if (n < 10) cout << n;
    else if (n < 100) cout << (n - 10) * 2 + 9;
    else if (n < 1000) cout << */

    for (i = 1; i <= ds(n); i++){
        s += (pow(10, i) - pow(10, (i - 1))) * i;
    }

    cout << s + (n - pow(10, ds(n)) + 1)  * (ds(n) + 1);

    return 0;
}
