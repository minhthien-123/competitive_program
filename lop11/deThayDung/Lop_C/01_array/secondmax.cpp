#include <bits/stdc++.h>
using namespace std;

long long n, sm = LLONG_MIN, mx = LLONG_MIN, i, a[1000005];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("secondmax.inp", "r", stdin);
    freopen("secondmax.out", "w", stdout);

    cin >> n;
    for (i = 0; i < n; i++){
        cin >> a[i];
        mx = max(a[i], mx);
    }

    //cout << mx << "\n";

    for (i = 0; i < n; i++)
        if (a[i] != mx) sm = max(sm, a[i]);

    if (sm < 0) cout << 0;
    else{
        cout << sm << "\n";
        for (i = 0; i < n; i++)
            if (a[i] == sm)
                cout << i + 1<< " ";
    }
}