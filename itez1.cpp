#include <bits/stdc++.h>
#define ll long long

const int maxn = 1e5 + 5;
const ll  inf  = 1e9 + 7;
int n, q, a[maxn];
ll st[4 * maxn];

void build(int id, int l, int r){
    if (l == r){
        st[id] = a[l];
        return;
    }

    int mid = l + r >> 1;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    st[id] = std::max(st[id * 2], st[id * 2 + 1]);
}

void update(int id, int l, int r, int x, int y){
    if (x < l || x > r) return;
    if (l == r){
        st[id] = y;
        return;
    }

    int mid = l + r >> 1;
    update(id * 2, l, mid, x, y);
    update(id * 2 + 1, mid + 1, r, x, y);
    st[id] = std::max(st[id * 2], st[id * 2 + 1]);
}

ll get(int id, int l, int r, int u, int v){
    if (v < l || r < u) return -inf;
    if (u <= l && r <= v) return st[id];

    int mid = l + r >> 1;
    ll get1 = get(id * 2, l, mid, u, v);
    ll get2 = get(id * 2 + 1, mid + 1, r, u, v);
    return std::max(get1, get2);
}


int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];
    build(1, 1, n);

    std::cin >> q;
    while(q--){
        int type, l, r;
        std::cin >> type >> l >> r;
        if (type == 1) update(1, 1, n, l, r);
        else           std::cout << get(1, 1, n, l, r) << "\n";
    }
}
