#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9;

long long power(long long x, long long y){
    if (y == 0) return 1;
    long long tmp = power(x, y / 2) % mod;
    if (y % 2 == 0) return (tmp * tmp) % mod;
    else            return (tmp * tmp) % mod * x % mod;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    long long n;
    cin >> n;
    long long s = 0;
    while (n--){
        long long p, x, y;
        cin >> p;
        y = p % 10;
        x = p / 10;
        s += power(x, y);
    }

    cout << s;
}
