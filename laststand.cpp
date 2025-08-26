#include <bits/stdc++.h>
using namespace std;

int n, ans, k;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("laststand.inp", "r", stdin);
    freopen("laststand.out", "w", stdout);

    cin >> n;

    if (n == 1) cout << 1;
    else{
        ans = 3;
        k = 1;
        for (int i = 2; i < n; i++){
            //cout << ans << " ";
            ans = ans + ans + 2 * k;
            k *= 2;
        }

        cout << ans;
    }
}
