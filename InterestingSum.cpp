#include <bits/stdc++.h>
using namespace std;

int t, a[1000005], n;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        sort(a + 1, a + n + 1);
        cout << a[n] - a[1] + a[n - 1] - a[2] << "\n";
    }

    return 0;
}
