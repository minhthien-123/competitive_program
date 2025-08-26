#include <bits/stdc++.h>
using namespace std;

int n, q, l, r, a[1000005];
long long s = 0;
vector<int> v;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];

    while (q--){
        cin >> l >> r;
        s = 0;
        v.clear();
        for (int i = 1; i <= n; i++) if (l <= a[i] && a[i] <= r) v.push_back(a[i]);
        //for (int i = 1)
        for (int i = 1; i < v.size(); i++) s += abs(v[i] - v[i - 1]);

        cout << s << "\n";
    }

    return 0;
}
