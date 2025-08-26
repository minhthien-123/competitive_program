#include <bits/stdc++.h>

const int maxn = 5e4 + 7;
const int inf  = 1e9 + 7;

struct tree{
    int Min, Max, val;

    static tree base(){
        return {inf, -inf, 2 * inf};
    }

    static tree merge(tree a, tree b){
        tree res;
        res.Min = std::min(a.Min, b.Min);
        res.Max = std::max(a.Max, b.Max);
        res.val = res.Max - res.Min;
        return res;
    }
};

int n, q;
int a[maxn];
tree st[4 * maxn];

void build(int id, int l, int r){
    if (l == r){
        st[id] = {a[l], a[l], 0};
        return ;
    }

    int mid = l + r >> 1;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    st[id] = tree::merge(st[id * 2], st[id * 2 + 1]);
}

tree get(int id, int l, int r, int u, int v){
    if (v < l || r < u) return tree::base();
    if (u <= l && r <= v) return st[id];

    int mid = l + r >> 1;
    tree get1 = get(id * 2, l, mid, u, v);
    tree get2 = get(id * 2 + 1, mid + 1, r, u, v);
    return tree::merge(get1, get2);
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen("nklineup.inp", "r", stdin);
    std::freopen("nklineup.out", "w", stdout);

    std::cin >> n >> q;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];
    build(1, 1, n);

    while(q--){
        int x, y;
        std::cin >> x >> y;
        tree ans = get(1, 1, n, x, y);
        std::cout << ans.val << "\n";
    }

    return 0;
}
