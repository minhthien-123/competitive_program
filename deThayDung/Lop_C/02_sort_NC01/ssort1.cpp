#include <bits/stdc++.h>
using namespace std;

long long i, j, n, m, d = 0, x, b[1000005];
map<long long, long long> a;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("ssort1.inp", "r", stdin);
    freopen("ssort1.out", "w", stdout);

    cin >> n >> m;
    if (n <= 100000 && m <= 100000){
        for (i = 0; i < n; i++){
            cin >> x;
            a[x]++;
        }

        for (i = 0; i < m; i++){
            cin >> x;
            if (a[x] > 0) d++;
        }
    }else{

        for (i = 0; i < n; i++){
            cin >> x;
            b[x]++;
        }

        for (i = 0; i < m; i++){
            cin >> x;
            if (b[x] > 0) d++;
        }

    }

    cout << d;

    return 0;

}
