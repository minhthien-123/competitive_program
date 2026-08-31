#include <bits/stdc++.h>
using namespace std;

int n, q, x, r, ans;
vector <int>a;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> r;
        a.push_back(r);
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < q; i++){
        cin >> x;
        ans =  (lower_bound(a.begin(), a.end(), x) - a.begin()) + 1;
        if (ans > n) cout << "NO" << "\n";
        else         cout << ans << "\n";
    }

    return 0;
}
