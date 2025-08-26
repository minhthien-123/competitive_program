#include <bits/stdc++.h>
using namespace std;

long long n, a, b;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("jog.inp", "r", stdin);
    freopen("jog.out", "w", stdout);

    cin >> n >> a >> b;
    cout << min(abs(a - b), n - max(a, b) + min(a, b));
}
