#include <bits/stdc++.h>
using namespace std;

long long x, n, i;
double sum = 0.0, a = 1, b = 1;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> x >> n;
    for (i = 1; i <= n; i++){
        a *= x;
        b *= i;
        sum += a / b;
    }

    cout << fixed << setprecision(2) << sum << endl;

    return 0;
}