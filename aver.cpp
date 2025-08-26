#include <bits/stdc++.h>
using namespace std;

long long i, n, j, en, beg, a[1000005], arr[1000005], prf[1000005], k, mx = LLONG_MIN;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("aver.inp","r",stdin);
    freopen("aver.out","w",stdout);

    cin >> n >> k;
    //cout << 0 << " ";
    for (i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] -= k;
        //cout << a[i] << " ";
    }
    //cout << "\n";

    prf[0] = 0;
    for (i = 1; i <= n; i++) prf[i] = prf[i - 1] + a[i];

    arr[n] = prf[n];
    for (i = n - 1; i > 0; i--) arr[i] = max(arr[i + 1], prf[i]);

    /*for (i = 0; i <= n; i++) cout << arr[i] << " ";
    cout << "\n";
    for (i = 0; i <= n; i++) cout << prf[i] << " ";
    cout << "\n";*/

    i = 1; j = 0;
    beg = 0; en = 0;

    while (i <= n && j <= n){
        while (i <= n && prf[j] <= arr[i]) i++;

        //cout << j << " " << i << "\n";

        mx = max(mx, i - j - 1);

        j++;
    }

    cout << mx;
}
