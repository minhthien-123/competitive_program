#include <bits/stdc++.h>
using namespace std;

long long i, n, j, en, beg, a[1000005], arr[1000005], prf[1000005];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //freopen("ps.inp","r",stdin);
    //freopen("ps.out","w",stdout);

    cin >> n;
    for (i = 1; i <= n; i++) cin >> a[i];

    prf[0] = 0;
    for (i = 1; i <= n; i++) prf[i] = prf[i - 1] + a[i];

    arr[n] = prf[n];
    for (i = n - 1; i > 0; i--) arr[i] = min(arr[i + 1], prf[i]);

    /*for (i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";
    for (i = 0; i < n; i++) cout << prf[i] << " ";
    cout << "\n";*/

    

    cout << prf[en] - prf[beg - 1];
}
