#include <bits/stdc++.h>
using namespace std;

long long n, a[1000005], d, s = 0, i, j;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("delarr.inp", "r", stdin);
    freopen("delarr.out", "w", stdout);

    cin >> n;
    for (i = 0; i < n; i++){
        cin >> a[i];
        s+=a[i];
    }

    sort(a, a + n);
    i = 0; j = n - 1;
    while (s != 0){
        if (s > 0){
            s -= a[j];
            j--;
        }else{
            s -= a[i];
            i++;
        }

        d++;
    }

    cout << d;

    return 0;

}
