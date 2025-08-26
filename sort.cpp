#include <bits/stdc++.h>
using namespace std;

int n, a[1000005];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("sort.inp", "r", stdin);
    freopen("sort.out", "w", stdout);

    n = 0;
    cin >> a[n];
    while (a[n] != 0){
        n++;
        cin >> a[n];
    }

    sort(a, a + n);

    for(int j = 0; j < n; j++) cout << a[j] << "\n";
}
