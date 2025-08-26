#include <bits/stdc++.h>
using namespace std;

int x, y;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> x >> y;
    if (min(x, y) + 3 > max(x, y)) cout << "Yes";
    else                           cout << "No";

    return 0;
}
