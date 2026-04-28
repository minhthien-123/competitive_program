#include <bits/stdc++.h>
using namespace std;

long long n, m, i, j, k, a[1000005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    freopen("udtseq.inp", "r", stdin);
    freopen("udtseq.out", "w", stdout);

    cin >> n >> m;

    while (m--){
        cin >> i >> j >> k;
        a[i] += k;
        a[j + 1] -= k;
    }

    for (i = 1; i <= n; i++) a[i] += a[i - 1];

    for (i = 1; i <= n; i++) cout << a[i] << " ";

    return 0;
}