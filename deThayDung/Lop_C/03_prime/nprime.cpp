#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll maxn = 10e6, n, i, j, m;
vector<bool> a(10e6, 1);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    freopen("nprime.inp", "r", stdin);
    freopen("nprime.out", "w", stdout);

    a[0] = a[1] = 0;
    for (i = 2; i * i <= maxn; i++){
        if (a[i]){
            for (j = i * i; j <= maxn; j += i){
                a[j] = 0;
            }
        }
    }

    cin >> n;
    m = sqrt(n);
    if (m * m != n) m++;
    cout << m << "\n";

    while (!a[m]) m++;

    cout << m * m;

    return 0;
}