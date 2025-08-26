#include <bits/stdc++.h>
using namespace std;

double a, b, c, s, s1, s2, p;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("length.inp", "r", stdin);
    freopen("length.out", "w", stdout);

    cin >> a >> b >> c >> s;
    p = (a + b + c) / 2.0;
    s1 = sqrt(p * (p - a) * (p - b) * (p - c));

    s2 = s1 - s;

    p = s2 / s1;

    cout << fixed << setprecision(2) << sqrt(p * a * a);

    return 0;
}
