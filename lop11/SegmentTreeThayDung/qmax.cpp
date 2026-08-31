#include <bits/stdc++.h>
#define ll long long

const ll maxn = 5e4 + 7;
const ll inf  = 1e9 + 7;

ll m, n, q;
ll a[maxn], st[4 * maxn], lazy[4 * maxn];

void fix(int id, int l, int r) {
    if (!lazy[id]) return;
    st[id] += lazy[id];

    if (l != r){
        lazy[2 * id] += lazy[id];
        lazy[2 * id + 1] += lazy[id];
    }

    lazy[id] = 0;
}

void update(int id, int l, int r, int u, int v, int val) {
    fix(id, l, r);
    if (v < l || r < u) return;
    if (l >= u && r <= v) {
        lazy[id] += val;
        fix(id, l, r);
        return;
    }
    int mid = l + r >> 1;
    update(2 * id, l, mid, u, v, val);
    update(2 * id + 1, mid + 1, r, u, v, val);
    st[id] = std::max(st[2 * id], st[2 * id + 1]);
}

ll get(ll id, ll l, ll r, ll u, ll v) {
    fix(id, l, r);
    if (v < l || r < u) return -inf;
    if (l >= u && r <= v) return st[id];

    ll mid  = l + r >> 1;
    ll get1 = get(2 * id, l, mid, u, v);
    ll get2 = get(2 * id + 1, mid + 1, r, u, v);
    return std::max(get1, get2);
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen("qmax.inp", "r", stdin);
    std::freopen("qmax.out", "w", stdout);

    std::cin >> n >> m;

    while(m--){
        ll u, v, k;
        std::cin >> u >> v >> k;
        update(1, 1, n, u, v, k);
    }

    //for (ll i = 0; i < 4 * n; i++)
        //std::cout << st[i] << " ";
    //std::cout << "\n";

    std::cin >> q;
    while(q--){
        ll x, y;
        std::cin >> x >> y;
        std::cout << get(1, 1, n, x, y) << "\n";
    }

    return 0;
}
