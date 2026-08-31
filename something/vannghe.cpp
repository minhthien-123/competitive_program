#include <bits/stdc++.h>
using namespace std;

long long m, n;

int main(){
    cin >> n >> m;
    cout << __gcd(n, m);
    cout << n / __gcd(n, m) << " " << m / __gcd(n, m);

}
