#include <bits/stdc++.h>
using namespace std;

unsigned long long n;

int main(){
    freopen("ezmath.inp", "r", stdin);
    freopen("ezmath.out", "w", stdout);

    cin >> n;
    cout << ((n % 2023) * ((n + 1) % 2023) * ((n + 2) % 2023) / 3) % 2023;
}
