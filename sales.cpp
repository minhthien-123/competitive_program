#include <bits/stdc++.h>
using namespace std;

long long n, i, k, m, d = 1, a[100005], t = 0;
bool kt = true;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    m = 0;
    for (i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n);

    for (i = 1; i < n; i++){
        if (a[i] == a[i - 1]) d++;
        else{
            //cout << d << "\n";
            if (d <= 1) kt = false;
            if      (d % 3 == 0) t += d / 3;
            else if (d % 3 == 1) t += (d - 4) / 3 + 2;
            else                 t += d / 3 + 1;
            d = 1;
        }
    }

    if (d <= 1) kt = false;
    if      (d % 3 == 0) t += d / 3;
    else if (d % 3 == 1) t += (d - 4) / 3 + 2;
    else                 t += d / 3 + 1;

    if (kt == true) cout << t;
    else            cout << -1;

    return 0;
}