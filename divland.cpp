#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio();
    cin.tie(0); cout.tie(0);


    freopen("divland.inp", "r", stdin);
    freopen("divland.out", "w", stdout);

    long long x, y, n, r, i, a, b, kt, d = 0;
    cin >> n >> r >> x >> y;

    for (i = 0; i < n; i++){
        cin >> a >> b;
        /*cout << a << " " << b << "\n";
        cout << x - r << " " << a << " " << x + r << "\n";
        cout << y - r << " " << b << " " << y + r << "\n\n";
        if (x - r < a && a < x + r && y - r < b && b < y + r){
            d++;
        }*/

        kt = sqrt(r * r * 2);
        if (abs(x - a) < kt && abs(y - b) < kt){
            d++;
        }
    }

    cout << d;

}
