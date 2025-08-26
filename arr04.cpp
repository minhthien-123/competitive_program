#include <bits/stdc++.h>
using namespace std;

long n, i, a[1000005], mx = LONG_MIN, k;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for (i = 0; i < n; i++){
        cin >> a[i];
        if (a[i] > mx && a[i] < k) mx = a[i];
    }

    cout << mx << "\n";

    for (i = 0; i < n; i++) if (a[i] == mx) cout << i + 1 << " ";

    return 0;
}
