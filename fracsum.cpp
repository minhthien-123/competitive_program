#include <bits/stdc++.h>
using namespace std;

long long a, b, c, d, x, y;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> a >> b >> c >> d;

    x = a * d + b * c;
    y = b * d;

    cout << x / __gcd(x, y) << " " << y / __gcd(x, y);

    return 0;

}
