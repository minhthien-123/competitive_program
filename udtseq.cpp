#include <bits/stdc++.h>
using namespace std;

long long n, m, i, j, k, a[1000005], b[1000005], x;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("udtseq.inp", "r", stdin);
    freopen("udtseq.out", "w", stdout);

    cin >> n >> m;
    for (int x = 1; x <= n; x++){
        cin >> i >> j >> k;
        a[i] += k;
        a[j + 1] -= k;
    }

    b[0] = 0;
    for (i = 1; i <= n; i++) b[i] = b[i - 1] + a[i];

    //for (i = 1; i <= n; i++) cout << a[i] << " ";
    //cout << "\n";

    for (i = 1; i <= n; i++) cout << b[i] << " ";

    return 0;
}
