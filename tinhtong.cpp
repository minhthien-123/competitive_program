#include <bits/stdc++.h>
using namespace std;

long long n, q, i, d, c, a[100005], prf[100005], k, b;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    for (i = 1; i <= n; i++) cin >> a[i];
    prf[0] = 0;
    for (i = 1; i <= n; i++) prf[i] = prf[i - 1] + a[i];


    for (i = 0; i < q; i++){
        cin >> k >> b;
        d = b % n;
        c = (b + k - 1) % n;
        if (d < c) cout << prf[c] - prf[d - 1] << "\n";
        else       cout << prf[n] - (prf[d - 1] - prf[c]) << "\n";
    }

    return 0;
}
