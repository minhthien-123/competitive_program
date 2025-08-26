#define task "segsqrss"
#include <bits/stdc++.h>
#define ll long long

const int maxn = 1e5 + 7;
int n, q;
ll a[maxn], st[4 * maxn], lazy[4 * maxn], lz[4 * maxn];

void build(int id, int l, int r){
    if (l == r){
        st[id] = a[l] * a[l];
        return;
    }

    int mid = l + r >> 1;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    st[id] = st[id * 2] + st[id * 2 + 1];
}

void fix(int id, int l, int r){
    if (lazy[id] == 0) return;
    st[id] += lazy[id];

    if (l != r){
        lazy[id * 2]     += lazy[id];
        lazy[id * 2 + 1] += lazy[id];
    }

    lazy[id] = 0;
}

void update(int id, int l, int r, int u, int v, ll x){
    fix(id, l, r);
    if (v < l || r < u) return;
    if (u <= l && r <= v){
        lazy[id] += x;
        fix(id, l, r);
        return;
    }

    int mid = l + r >> 1;
    update(id * 2, l, mid, u, v, x);
    update(id * 2 + 1, mid + 1, r, u, v, x);

    st[id] = st[id * 2] + st[id * 2 + 1];
}

void fix1(int id, int l, int r){
    if (lz[id] == 0) return;

    st[id] = lz[id];
    if (l != r){
        lz[id * 2] = lz[id];
        lz[id * 2 + 1] = lz[id];
    }

    lz[id] = 0;
}

void update1(int id, int l, int r, int u, int v, ll x){
    fix1(id, l, r);
    if (v < l || r < u) return;
    if (u <= l && r <= v){
        lz[id] = x;
        fix1(id, l, r);
        return;
    }

    int mid = l + r >> 1;
    update1(id * 2, l, mid, u, v, x);
    update1(id * 2 + 1, mid + 1, r, u, v, x);

    st[id] = st[id * 2] + st[id * 2 + 1];
}

ll get(int id, int l, int r, int u, int v){
    if (v < l || r < u) return 0;
    if (u <= l && r <= v) return st[id];

    int mid = l + r >> 1;
    ll get1 = get(id * 2, l, mid, u, v);
    ll get2 = get(id * 2 + 1, mid + 1, r, u, v);

    return get1 + get2;
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen(task".inp", "r", stdin);
    std::freopen(task".out", "w", stdout);

    std::cin >> n >> q;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];
    build(1, 1, n);

    for (int i = 1; i <= 4 * n; i++)
        std::cout << st[i] << " ";
    std::cout << "\n";

    while (q--){
        int type, l, r;
        std::cin >> type >> l >> r;
        if (type == 2) std::cout << get(1, 1, n, l, r) << "\n";
        else{
            ll val;
            std::cin >> val;
            if (type == 0) update1(1, 1, n, l, r, val);
            else           update(1, 1, n, l, r, val);
        }
    }

    return 0;
}
