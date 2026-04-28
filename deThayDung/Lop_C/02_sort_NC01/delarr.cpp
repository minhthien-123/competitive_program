#include <bits/stdc++.h>
using namespace std;

long long n, i, a[1000005], s = 0, beg, en;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    freopen("delarr.inp", "r", stdin);
    freopen("delarr.out", "w", stdout);

    cin >> n;

    for (i = 0; i < n; i++){
        cin >> a[i];
        s += a[i];
    }

    sort(a, a + n);
    beg = 0; en = n - 1;
    while (s != 0)
        if (s > 0){
            s -= a[en];
            en--;
        }else{
            s += a[beg];
            beg++;
        }

    cout << en - beg + 1;
}