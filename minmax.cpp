#include <bits/stdc++.h>
using namespace std;

long long n, i, d = 0, d1 = 0;
long long a[1000005];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (i = 1; i <= n; i++){
        cin >> a[i];
        if (a[i] == i) d++;
    }

    d = d * (d - 1) / 2;

    for (i = 1; i <= n; i++) if (a[a[i]] == i && a[i] != i) d1++;

    d1 = d1 * (d1 - 1) / 2;

    cout << d + d1;
}
