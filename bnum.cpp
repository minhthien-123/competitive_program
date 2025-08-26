#include <bits/stdc++.h>
using namespace std;

long long n, s;
bool flag = true;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("bnum.inp", "r", stdin);
    freopen("bnum.out", "w", stdout);

    cin >> n;
    s = 0;
    while (n != 0){
        s += (n % 10) * (n % 10);
        n /= 10;
    }

    for (long long i = 2; i * i <= s; i++){
        if (s % i == 0) flag = false;
    }

    if (flag) cout << 1;
    else      cout << -1;

    cout << "\n";

    cout << s;
}
