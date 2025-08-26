#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int maxn = 3e5;
int t;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
	while (t--){
        int q, n, a[maxn];
        cin >> n >> q;

        a[0] = a[n + 1] = 0;
        for (int i = 1; i <= n; ++i) cin >> a[i];

        ll ans = 0;
        for (int i = 1; i <= n; ++i){
            if (a[i] > a[i - 1] && a[i] > a[i + 1]) ans += a[i];
            if (a[i] < a[i - 1] && a[i] < a[i + 1]) ans -= a[i];
        }

        cout << ans << '\n';
        while (q--) {
            int l, r;
            cin >> l >> r;
            set<int> s;
            s.insert(l - 1);
            s.insert(l);
            s.insert(l + 1);
            s.insert(r - 1);
            s.insert(r);
            s.insert(r + 1);

            for (int i : s)
                if (i != 0 && i <= n){
                    if (a[i] > a[i - 1] && a[i] > a[i + 1]) ans -= a[i];
                    if (a[i] < a[i - 1] && a[i] < a[i + 1]) ans += a[i];
                }


            swap(a[l], a[r]);

            for (int i : s)
                if (i != 0 && i <= n){
                    if (a[i] > a[i - 1] && a[i] > a[i + 1]) ans += a[i];
                    if (a[i] < a[i - 1] && a[i] < a[i + 1]) ans -= a[i];
                }
            cout << ans << '\n';
        }
	}
}
