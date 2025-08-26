#include <bits/stdc++.h>
using namespace std;

long long a, b, i, j, t;

long long uoc(long long n){
    long long i, j, s = 0;
    for (i = 1; i * i <= n; i++){
        if (n % i == 0){
            j = n / i;
            if (i == j) s += i;
            else        s += i + j;
        }
    }

    return s;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("friends.inp", "r", stdin);
    freopen("friends.out", "w", stdout);

    cin >> t;
    for (i = 0; i < t; i++){
        cin >> a >> b;

        //cout << uoc(a) << " " << uoc(b) << "\n";
        if (uoc(a) - a == b && a == uoc(b) - b) cout << "YES" << "\n";
        else                            cout << "NO"  << "\n";
    }


    return 0;
}
