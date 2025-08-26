#include <bits/stdc++.h>
using namespace std;

long long n, m, a, mod = 10e9 + 7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m >> a;

    n = (n - n % a + a) % mod;
    m = (m - m % a + a) % mod;
    a = (a % mod) * (a % mod);

    cout << m * n / a;

}
