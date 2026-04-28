#include <bits/stdc++.h>
#define ll long long

const int maxn = 2e5 + 9;
const ll  inf  = 1e9 + 9;
int n, q;
ll a[maxn], st[4 * maxn], prf[maxn], lazy[4 * maxn];

void build(int id, int l, int r) {
    if (l == r) {
        st[id] = prf[l];
        return;
    }
    int mid = l + r >> 1;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
    st[id] = std::max(st[2 * id], st[2 * id + 1]);
}

void fix(int id, int l, int r) {
    if (lazy[id] == inf) return;
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

long long get(int id, int l, int r, int u, int v) {
    fix(id, l, r);
    if (v < l || r <  u) return -inf;
    if (l >= u && r <= v) return st[id];

    int mid  = l + r >> 1;
    long long get1 = get(2 * id, l, mid, u, v);
    long long get2 = get(2 * id + 1, mid + 1, r, u, v);
    return std::max(get1, get2);
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen("prefixsumqueries.inp", "r", stdin);
    std::freopen("prefixsumqueries.out", "w", stdout);

    std::cin >> n >> q;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];
    for (int i = 1; i <= n; i++)
        prf[i] = prf[i - 1] + a[i];
    build(1, 1, n);
    while (q--){
        int type, l, r;
        std::cin >> type >> l >> r;
        if (type == 1){
            update(1, 1, n, l, n, r - a[l]);
        }else
            std::cout << get(1, 1, n, l, r) - a[l - 1] << "\n";
    }

    return 0;
}
