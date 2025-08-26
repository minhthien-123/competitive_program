#include <bits/stdc++.h>
using namespace std;

const long long m = 2020;

long long n;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("cs15.inp", "r", stdin);
    freopen("cs15.out", "w", stdout);

    cin >> n;
    cout << ((n % m) * ((n + 1) % m) * ((n + 2) % m)) % m / 3;
}
