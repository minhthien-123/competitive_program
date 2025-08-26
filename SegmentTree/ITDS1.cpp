#include <bits/stdc++.h>
#define ll long long

const int maxn = 1e5 + 7;
const int  inf  = 1e9 + 7;

int n, a[maxn], m;
std::multiset<int> st[4 * maxn];

void build(int id, int l, int r){
    if (l == r){
        st[id].insert(a[l]);
        return ;
    }

    int mid = l + r >> 1;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    st[id] = st[id * 2 + 1];
    for (auto x : st[id * 2]) st[id].insert(x);
}

void update(int id, int l, int r, int i, int old, int val){
    if (i < l || i > r) return ;
    if (l == r){
        st[id].clear();
        st[id].insert(val);
        return;
    }

    int mid = l + r >> 1;
    update(id * 2, l, mid, i, old, val);
    update(id * 2 + 1, mid + 1, r, i, old, val);
    st[id].erase(st[id].find(old));
    st[id].insert(val);
}

int get(int id, int l, int r, int u, int v, int k){
    if (v < l || r < u) return -inf;
    if (u <= l && r <= v){
        auto it = st[id].lower_bound(k);
        if (it == st[id].end()) return inf;
        return *it;
    }

    int mid = l + r >> 1;
    int get1 = get(id * 2, l, mid, u, v, k);
    int get2 = get(id * 2 + 1, mid + 1, r, u, v, k);
    return std::max(get1, get2);
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i) std::cin >> a[i];
    build(1, 1, n);

    while (m--){
        int type, l, r, k;
        std::cin >> type;
        if (type == 1) {
            std::cin >> l >> k;
            update(1, 1, n, l, a[l], k);
            a[l] = k;
        }
        else {
            std::cin >> l >> r >> k;
            int ans = get(1, 1, n, l, r, k);
            if (ans == inf) std::cout << -1;
            else            std::cout << ans;
            std::cout << "\n";
        }
    }


    return 0;
}
