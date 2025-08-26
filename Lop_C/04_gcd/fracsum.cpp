#include <bits/stdc++.h>
using namespace std;

long long a, b, c, d, x, y, z;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    freopen("fracsum.inp", "r", stdin);
    freopen("fracsum.out", "w", stdout);

    cin >> a >> b >> c >> d;

    z = b * d / __gcd(b, d);

    //cout << z;

    x = z / b;
    y = z / d;

    cout << a * x + c * y << " " << z;
}