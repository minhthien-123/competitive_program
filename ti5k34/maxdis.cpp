#include <bits/stdc++.h>
#define task "maxdis"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

int n, l, r;

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen(task".inp", "r", stdin);
    std::freopen(task".out", "w", stdout);

    std::cin >> n >> l >> r;
    std::vector<int> a(n), ans = {l, r};

    for (int i = 0; i < n; i++){
        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end());

    int maxdis = -1;
    int res = l;

    for (int i = 0; i < n; i++){
        ans.pb(a[i]);
        if (i > 0){
            int m = a[i] + (a[i] - a[i - 1]) / 2;
            if (l <= m && m <= r) ans.pb(m);
            if (l <= (m + 1) && (m + 1) <= r) ans.pb(m + 1);
            if (l <= (m - 1) && (m - 1) <= r) ans.pb(m - 1);
        }
    }

    for (int x : ans){
        if (x < l || x > r) continue;

        auto pos = std::lower_bound(a.begin(), a.end(), x);
        int dis = LLONG_MAX;

        if (pos != a.end()) {
            dis = std::min(dis, abs(x - *pos));
        }
        if (pos != a.begin()) {
            dis = std::min(dis, abs(x - *(pos - 1)));
        }

        if (dis > maxdis) {
            maxdis = dis;
            res = x;
        } else if (dis == maxdis) {
            res = std::max(res, x);
        }
    }

    std::cout << res;

    return 0;
}

