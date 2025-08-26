#include <bits/stdc++.h>
#define ll long long

const ll inf  = 1e9 + 7;
const ll maxn = 1e5 + 7;

ll n, m;
ll a[maxn], st[4 * maxn], lazy[4 * maxn];

void fix(ll id, ll l, ll r){
    if (lazy[id] == 0) return;

    st[id] += lazy[id];
    if (l != r){
        st[id * 2] += lazy[id];
        st[id * 2 + 1] += lazy[id];
    }

    lazy[id] = 0;
}

void update(ll id, ll l, ll r, ll i, ll val){
    fix(id, l, r);
    if (i < l || i > r) return;
    if (l == r){
        st[id] = val;
        return ;
    }

    ll mid = l + r >> 1;
    update(id * 2, l, mid, i, val);
    update(id * 2 + 1, mid + 1, r, i, val);
    st[id] = std::max(st[id * 2], st[id * 2 + 1]);
}

ll get(ll id, ll l, ll r, ll u, ll v){
    if (v < l || r < u) return 0;
    if (u <= l && r <= v) return st[id];

    ll mid = l + r >> 1;
    ll get1 = get(id * 2, l, mid, u, v);
    ll get2 = get(id * 2 + 1, mid + 1, r, u, v);
    return std::max(get1, get2);
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen("querysum.inp", "r", stdin);
    std::freopen("querysum.out", "w", stdout);

    std::cin >> n >> m;

    while(m--){
        char type;
        ll x, y, val;
        std::cin >> type >> x >> y;
        if (type == 0) {
            update(1, 1, n, x, y);
        }
        else std::cout << get(1, 1, n, x, y) << "\n";
    }

    return 0;
}
