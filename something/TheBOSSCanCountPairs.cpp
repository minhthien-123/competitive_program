#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;

        int a[n + 5], b[n + 5];

        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) cin >> b[i];

        int d = 0;

        for (int i = 1; i < n; i++){
            for (int j = i + 1; j <= n; j++){
                if (a[i] * a[j] == b[i] + b[j]){
                    //cout << i << " " << j << "\n";
                    d++;
                }
            }
        }

        cout << d << "\n";
    }
}
