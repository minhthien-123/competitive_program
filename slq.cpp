#include <bits/stdc++.h>
using namespace std;

long long sum(long long x){
    long long s = 0;
    while (x > 0){
        s += x % 10;
        x /= 10;
    }

    return s;
}

long long n, res = 1000000000, y, m, ans, i;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("slq.inp", "r", stdin);
    freopen("slq.out", "w", stdout);

    cin >> n;

    i = 1;
    while (i * i + sum(i) * i - n != 0 && i <= 1e6) i++;

    if (i == 1e6 + 1) i = -1;
    cout << i;
}
