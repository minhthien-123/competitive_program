#include <bits/stdc++.h>
using namespace std;

long long n, q, k, x, a[1000005], b[1000005], s, i, m;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    b[0] = 0;
    for (i = 1; i <= n; i++){
        cin >> a[i];
        b[i] = b[i - 1] + a[i];
    }

    for (i = 1; i <= q; i++){
        cin >> k >> x;
        if (x % n != 0) x = x % n;

        if (x + k <= n) cout << b[x + k - 1] - b[x - 1];
        else{
            k = k - n + x;
            s = b[n] - b[x - 1];
            //cout << s << " ";

            m = k / n;
            s = s + b[n] * m;
            //cout << s << " ";

            m = k % n;
            if (m != 0) s = s + b[m - 1];

            cout << s;
        }

        cout << "\n";

    }

}