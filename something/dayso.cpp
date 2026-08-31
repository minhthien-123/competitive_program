#include <bits/stdc++.h>
#define task "dayso"
#define ll long long

const int maxn = 1e5 + 6;
const ll  inf  = LLONG_MIN;

struct tree{
    ll pre, suf, sum, summax;

    static tree base(){
        return {-inf, -inf, 0, -inf};
    }

    static tree merge(tree a, tree b){
        tree res;
        res.pre = std::max(a.pre, a.sum + b.pre);
        res.suf = std::max(b.suf, b.sum + a.suf);
        res.sum = a.sum + b.sum;
        res.summax = std::max({a.suf + b.pre, a.summax, b.summax});
        return res;
    }
};

int n, l, r;
ll  ans = LLONG_MIN, a[maxn];
tree st[4 * maxn];

void build(int id, int l, int r){
    if (l == r){
        st[id] = {a[l], a[l], a[l], a[l]};
        return;
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

    std::freopen(task".inp", "r", stdin);
    std::freopen(task".out", "w", stdout);

    std::cin >> n >> l >> r;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];

    build(1, 1, n);
    for (int i = 1; i <= n; i++)
        ans = std::max(ans, get(1, 1, n, i, i + (r - l + 1)).summax);

    std::cout << ans;

    return 0;
}
