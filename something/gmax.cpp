#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll N = 1e5;

struct tree{
    ll Min, Max, val;
    tree(){};
    tree(int _Min, int _Max, int _val){Min = _Min, Max = _Max, val = _val;}
};

tree st[4 * N];
ll n, a[N + 5], m;

tree build(tree x, tree y){
    return tree(min(x.Min, y.Min), max(x.Max, y.Max), max(y.Max - x.Min, max(x.val, y.val)));
}

void buildTree(ll id, ll l, ll r){
    if (l == r){
        st[id].Min = min(a[l], a[l - 1]);
        st[id].Max = a[r];
        st[id].val = a[r] - a[l - 1];
        return;
    }

    ll mid = (l + r) / 2;
    buildTree(id * 2, l, mid);
    buildTree(id * 2 + 1, mid + 1, r);

    st[id] = build(st[id * 2], st[id * 2 + 1]);
}

/*void update(ll id, ll l, ll r, ll k, ll x){
    if (k < l || r < k) return;
    if (l == r){
        st[id].Min = min();
        st[id].Min
        return;
    }

    ll mid = (l + r) / 2;
    update(id * 2, l, mid);
    update(id * 2 + 1, mid + 1, r);

    st[id] = build(st[id * 2], st[id * 2 + 1]);
}*/

tree get(ll id, ll l, ll r, ll x, ll y){
    if (r < x || y < l) return tree(LLONG_MAX, LLONG_MIN, LLONG_MIN);
    if (x <= l && r <= y) return st[id];

    ll mid = (l + r) / 2;
    return build(get(id * 2, l, mid, x, y), get(id * 2 + 1, mid + 1, r, x, y));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (ll i = 1; i <= n; i++){
        cin >> a[i];
        a[i] += a[i - 1];
    }

    buildTree(1, 1, n);

    while (m--){
        int x, y;
        cin >> x >> y;
        a[x] = y;
        buildTree(1, 1, n);
        for (ll i = 1; i <= n; i++) cout << a[i] << " ";
        cout << "\n";
        for (ll i = 1; i <= 4 * n; i++) cout << st[i].val << " ";
        cout << "\n";
        cout << get(1, 1, n, 1, n).val << "\n";
    }
}
