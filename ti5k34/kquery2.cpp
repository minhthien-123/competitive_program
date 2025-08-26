#include <bits/stdc++.h>
#define task "kquery"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5 + 7;
const int maxm = 320;
const int maxx = 1e4;

int n, q, m;
int bit[maxm + 7][maxx + 7], a[maxn], ans;

void update(int l, int r, int val) {
    while (l <= maxm) {
        int x = r;
        while (x <= maxx) {
            bit[l][x] += val;
            x += x & -x;
        }
        l += l & -l;
    }
}

int get(int l, int r) {
    int res = 0;
    while (l > 0) {
        int x = r;
        while (x > 0) {
            res += bit[l][x];
            x -= x & -x;
        }
        l -= l & -l;
    }
    return res;
}

int query(int l, int r, int u, int v) {
    return get(u, v) - get(l - 1, v) - get(u, r - 1) + get(l - 1, r - 1);
}

signed main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task ".inp", "r")) {
        std::freopen(task ".inp", "r", stdin);
        std::freopen(task ".out", "w", stdout);
    }

    std::cin >> n;
    m = sqrt(n);

    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        update(i / m + 1 - (i % m == 0), a[i], 1);
    }

    std::cin >> q;
    while (q--) {
        char type;
        std::cin >> type;
        if (type == 'S') {
            int id, val;
            std::cin >> id >> val;
            int tmp = id / m + 1 - (id % m == 0);
            update(tmp, a[id], -1);
            update(tmp, val, 1);
            a[id] = val;
        } else {
            int u, v, k;
            std::cin >> u >> v >> k;
            int l = u / m + 1, r = v / m + 1;
            ans = 0;
            if (l == r) {
                for (int i = u; i <= v; i++) {
                    ans += (a[i] > k);
                }
            } else {
                ans = query(l + 1, k + 1, r - 1, maxx);
                for (int i = u; i <= l * m; i++) {
                    ans += (a[i] > k);
                }
                for (int i = (r - 1) * m + 1; i <= v; i++) {
                    ans += (a[i] > k);
                }
            }
            std::cout << ans << "\n";
        }
    }

    return 0;
}
