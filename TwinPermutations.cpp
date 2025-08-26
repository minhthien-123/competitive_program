#include <bits/stdc++.h>
using namespace std;

int t, n, a[105], beg;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while (t--){
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            cout << n + 1 - a[i] << " ";
        }

        cout << "\n";
    }
}
