#include <bits/stdc++.h>
using namespace std;

long long t, n, i;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while (t--){
        cin >> n;

        long long a[2 * n + 5], s = 0;
        for (i = 0; i < 2 * n; i++) cin >> a[i];
        sort(a, a + 2 * n);
        for (i = n; i < 2 * n; i++) s += a[i];

        cout << s << "\n";
    }

    return 0;
}
