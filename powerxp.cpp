#include <bits/stdc++.h>
using namespace std;

unsigned long long power(unsigned long long x, unsigned long long y, unsigned long long m){
    if (y == 0) return 1;
    long long tmp = power(x, y / 2, m);
    if (y % 2 == 0) return (tmp * tmp) % m;
    else            return (tmp * tmp) % m * x % m;
}

unsigned long long a, b, m;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("powerxp.inp", "r", stdin);
    freopen("powerxp.out", "w", stdout);

    cin >> a >> b >> m;
    //cout << power(a, b, m) % m << "\n";
    //cout << power(b, a, m) % m << "\n";
    cout << power(a, b, m) * power(b, a, m) % m;
}
