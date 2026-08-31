    #include <bits/stdc++.h>
using namespace std;

long double a, b, c, p;

int main(){
    cin >> a >> b >> c;
    p = (a + b + c) / 2;
    p = sqrt(p * (p - a) * (p - b) * (p - c));
    cout << fixed << setprecision(5) << p;

    return 0;
}
