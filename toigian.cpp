#include <bits/stdc++.h>
using namespace std;

long long a, b;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("toigian.inp", "r", stdin);
    freopen("toigian.out", "w", stdout);

    cin >> a >> b;
    cout << a / __gcd(a, b) << " "<< b / __gcd(a, b);

}
