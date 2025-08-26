#include <bits/stdc++.h>
using namespace std;

long long a, b, ans;

long long power(long long x, long long y, long long m){
    if (y == 0) return 1;
    long long tmp = power(x, y / 2, m);
    if (y % 2 == 0) return (tmp * tmp) % m;
    else            return (tmp * tmp) % m * x % m;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("rectcut.inp", "r", stdin);
    freopen("rectcut.out", "w", stdout);

    cin >> a >> b;

    cout << power(2, a + b - 2, 123456789);
}
