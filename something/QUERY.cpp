#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n, a[1000005], x, y, query, q;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("QUERY.inp", "r", stdin);
    freopen("QUERY.out", "w", stdout);

    cin >> n >> q;
    a[0] = 0;
    for (ll i = 1; i <= n; i++){
        cin >> a[i];
        a[i] += a[i - 1];
    }

    for (int i = 1; i <= n; i++) cout << a[i] << " ";
    cout << "\n";

    while (q--){
        cin >> query >> x >> y;
        if (query == 0) cout << a[y] << "\n";
        else             cout << a[x] - a[x - y] << "\n";
    }
}
