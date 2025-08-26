#include <bits/stdc++.h>
#define task "codeforces"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

int n, m, q;

void solve() {
    std::cin >> n >> m >> q;

    std::vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        std::cin >> b[i];
    }

    std::vector<int> next(n + 1, -1);
    std::unordered_map<int, int> pos;

    for (int i = n - 1; i >= 0; i--) {
        pos[a[i]] = i;
        if (i + 1 < n) next[i] = pos[a[i+1]];
    }

    auto check = [&](std::vector<int> &b) -> bool {
        int j = 0;
        for (int i = 0; i < m; i++) {
            if (j < n && a[j] == b[i]) j++;
            if (j == n) break;
        }
        return j == n;
    };

    if (check(b)) {
        std::cout << "YA\n";
    } else {
        std::cout << "TIDAK\n";
    }

    for (int i = 0; i < q; i++) {
        int u, v;
        std::cin >> u >> v;
        b[u - 1] = v;

        if (check(b)) {
            std::cout << "YA\n";
        } else {
            std::cout << "TIDAK\n";
        }
    }
}

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen(task".inp", "r", stdin);
    std::freopen(task".out", "w", stdout);

    int t;
    std::cin >> t;
    while(t--){
        solve();
    }

    return 0;
}

