#include <bits/stdc++.h>
#define task "itladder"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

const int mod  = 1e9 + 7;
const int maxn = 1e5 + 7;

int n, m;
int st[4 * maxn];
ii lazy[4 * maxn];

void fix(int id, int l, int r) {
    int a = lazy[id].fi;
    int b = lazy[id].se;
    st[id] += (a * (r + l) * (r - l + 1) / 2) % mod;
    st[id] %= mod;
    st[id] += (b * (r - l + 1)) % mod;
    st[id] %= mod;

    if (l != r) {
        lazy[2 * id].fi  = (lazy[2 * id].fi  + a) % mod;
        lazy[2 * id].se = (lazy[2 * id].se + b) % mod;
        lazy[2 * id + 1].fi  = (lazy[2 * id + 1].fi  + a) % mod;
        lazy[2 * id + 1].se = (lazy[2 * id + 1].se + b) % mod;
    }
    lazy[id] = {0, 0};
}

void update(int id, int l, int r, int u, int v, int a, int b) {
    fix(id, l, r);
    if (l >  v || r <  u) return;
    if (l >= u && r <= v) {
        lazy[id].fi  = a;
        lazy[id].se = (b - u * a + mod * mod) % mod;
        fix(id, l, r);
        return;
    }

    int mid = l + r >> 1;
    update(2 * id, l, mid, u, v, a, b);
    update(2 * id + 1, mid + 1, r, u, v, a, b);

    st[id] = (st[2 * id] + st[2 * id + 1]) % mod;
}

int get(int id, int l, int r, int u, int v) {
    fix(id, l, r);
    if (l >  v || r <  u) return 0;
    if (l >= u && r <= v) return st[id];

    int mid  = l + r >> 1;
    int get1 = get(2 * id, l, mid, u, v);
    int get2 = get(2 * id + 1, mid + 1, r, u, v);
    return (get1 + get2) % mod;
}

signed main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    //std::freopen(task".inp", "r", stdin);
    //std::freopen(task".out", "w", stdout);

    std::cin >> n >> m;
    while (m--) {
        int type, l, r, a, b;
        std::cin >> type >> l >> r;
        if (type == 1) {
            std::cin >> a >> b;
            update(1, 1, n, l, r, a, b);
        }
        else std::cout << get(1, 1, n, l, r) << '\n';
    }

    return 0;
}