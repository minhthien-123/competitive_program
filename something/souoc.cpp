#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll n, d;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("souoc.inp", "r", stdin);
    freopen("souoc.out", "w", stdout);

    cin >> n;
    for (ll i = 1; i <= trunc(sqrt(n)); i++){
        if (n % i == 0){
            ll j = n / i;
            if (i % 2 != 0) d++;
            //cout << i << " " << j << "\n";
            if (i != j){
                if (j % 2 != 0) d++;
            }
        }
    }

    cout << d;
}
