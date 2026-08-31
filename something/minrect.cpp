#include <bits/stdc++.h>
using namespace std;

long long a1, a2, b1, b2;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("minrect.inp", "r", stdin);
    freopen("minrect.out", "w", stdout);

    cin >> a1 >> b1 >> a2 >> b2;
    cout << abs(a1 - a2) * abs(b1 - b2);
}
