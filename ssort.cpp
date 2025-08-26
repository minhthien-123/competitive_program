#include <bits/stdc++.h>
using namespace std;

int n, m, x, d = 0, a[1000005];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("ssort.inp", "r", stdin);
    freopen("ssort.out", "w", stdout);

    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> x;
        a[x]++;
    }

    for (int i = 0; i < m; i++){
        cin >> x;
        if (a[x] > 0) d++;
    }

    cout << d;

    return 0;

}
