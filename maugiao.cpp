#include <bits/stdc++.h>
using namespace std;

long long n, i, x, a[1000005], k, tmp;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    freopen("maugiao.inp", "r", stdin);
    freopen("maugiao.out", "w", stdout);

    cin >> n >> k;
    for (i = 1; i <= n; i++)
        cin >> a[i];

    k = a[k];

    tmp = a[1];
    for (i = 2; i <= n; i++){
        x = max(tmp, a[i]);
        if (x == k){
            cout << i - 1;
            return 0;
        }else tmp = min(tmp, a[i]);

        //cout << tmp << " ";
    }

    cout << -1;

    return 0;

}