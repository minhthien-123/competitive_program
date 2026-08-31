#include <bits/stdc++.h>
using namespace std;

long double a, b;
long long n, m;

long double power(long double x, long long y, long long m){
    if (y == 1) return x;
    else {
        if (y % 2 == 0) return ((power(x, y / 2, m) % m) * (power(x, y / 2, m) % m)) % m;
        else            return ((power(x, y / 2 + 1, m) % m) * (power(x, y / 2, m) % m)) % m;
    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //freopen("fibomod.inp", "r", stdin);
    //freopen("fibomod.out", "w", stdout);

    cin >> n >> m;

    a = (1 + sqrt(5)) / 2;
    b = (1 - sqrt(5)) / 2;

    //cout << a;
    cout << power(a, n, m);

    return 0;
}
