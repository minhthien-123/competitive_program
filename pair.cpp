#include <bits/stdc++.h>
using namespace std;

long long a, b, n;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> a >> b;

    a = n - a;
    b = n - b;
    swap(a, b);

    //cout << a << " " << b << "\n";
    //cout << b - a + 1 << " " << b + a << "\n" ;

    cout << (b - a + 1) * (b + a) / 2;
}
