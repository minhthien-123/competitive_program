#include <bits/stdc++.h>
using namespace std;

struct minhthiendeptrai{
    int val, dex;
};

int m, n, ans, i, j;
char x;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //freopen("maxrect.inp", "r", stdin);
    //freopen("maxrect.out", "w", stdout);

    cin >> m >> n;

    ans = 0;

    vector<int> a(n, 0), beg(n), en(n);

    for (i = 0; i < m; i++){
        for (j = 0; j < n; j++) {
            cin >> x;
            if (x == 'B') a[j] = 0;
            else          a[j] += 1;
        }

        vector<minhthiendeptrai> v;

        for (j = 0; j < n; j++) {
            while (!v.empty() && v.back().val >= a[j]) v.pop_back();

            if (v.empty()) beg[j] = -1;
            else           beg[j] = v.back().dex;

            v.push_back({a[j], j});
        }

        v.clear();

        for (j = n - 1;j >= 0; j--) {
            while (!v.empty() && v.back().val >= a[j]) v.pop_back();

            if (v.empty()) en[j] = n;
            else           en[j] = v.back().dex;

            v.push_back({a[j], j});
        }

        for (j = 0; j < n; j++) {
            ans = max(ans, a[j] * (en[j] - beg[j] - 1));
        }
    }

    cout << ans;
    return 0;
}
