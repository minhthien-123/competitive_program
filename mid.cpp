#include <bits/stdc++.h>
using namespace std;

int a, b, x, y;

int main() {
    cin >> x >> y;

    a = min(x, y);
    b = max(x, y);

    //cout << a << " " << b << "\n";

    if (a == 0){
        cout << 1;
    }else if (b == 0){
        cout << -1;
    }else if (a < 0){
        if (b < 0) cout << b - 1;
        else       cout << 0;
    }else if (a > 0){
        cout << a + 1;
    }
}
