#include <bits/stdc++.h>
using namespace std;

long i, n, k, x, m, d;
map<long, long> a;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for (i = 0; i < n; i++){
        cin >> x;
        a[x % k]++;
    }

    if (a[0] > 1) d = n - a[0] + 1;
    else          d = n;


    if (n % 2 == 0) {
        m = n / 2 - 1;
    }
    else            m = n / 2;

    if (k % 2 == 0 && a[k / 2] > 0) d++;

    //cout << d << "\n";

    //for (i = 0; i < n; i++) cout << a[i] << " ";

    for (long i = 1; i <= m; i++){
        //cout << i << ":" << a[i] << " " << k - i << ":" << a[k - i] << " " << min(a[i], a[k - i]) << "\n";
        d = d - (min(a[i], a[k - i]));
    }



    cout << d;

    //return 0;

}
