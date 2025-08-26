#include <bits/stdc++.h>
#define ll long long

const ll maxn = 1e5 + 7;
const ll inf  = 1e9 + 7;
ll n, m;
ll a[maxn], st[4 * maxn];

void buildTree(ll id, ll l, ll r){
    if (l == r){
        st[id] = a[l];
        return ;
    }

    ll mid = (l + r) / 2;

    buildTree(id * 2, l, mid);
    buildTree(id * 2 + 1, mid + 1, r);

    ll upd1 = st[id * 2];
    ll upd2 = st[id * 2 + 1];
    if (upd1 < 0 && upd2 < 0)
        st[id] = 0;
    else if (upd1 > 0 && upd2 > 0)
        st[id] = std::min(upd1, upd2);
    else
        st[id] = std::max(upd1, upd2);
}

void update(ll id, ll l, ll r, ll i, ll val){
    if (i < l || i > r) return;
    if (l == r){
        st[id] = val;
        return ;
    }

    ll mid = l + r >> 1;
    update(id * 2, l, mid, i, val);
    update(id * 2 + 1, mid + 1, r, i, val);
    ll upd1 = st[id * 2];
    ll upd2 = st[id * 2 + 1];
    if (upd1 < 0 && upd2 < 0)
        st[id] = 0;
    else if (upd1 > 0 && upd2 > 0)
        st[id] = std::min(upd1, upd2);
    else
        st[id] = std::max(upd1, upd2);
}

int get(int id, int l, int r, int u, int v){
    if (v < l || r < u) return inf;
    if (u <= l && r <= v) return st[id];

    ll mid = l + r >> 1;
    ll get1 = get(id * 2, l, mid, u, v);
    ll get2 = get(id * 2 + 1, mid + 1, r, u, v);
    return std::min(get1, get2);
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen("lis.inp", "r", stdin);
    std::freopen("lis.out", "w", stdout);

    std::cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }

    buildTree(1, 1, n);

    while(m--){
        char c;
        std::cin >> c;
        if (c == 'S'){
            ll u, v;
            std::cin >> u >> v;
            update(1, 1, n, u, v);
        }else
            std::cout << get(1, 1, n, 1, n) << "\n";
    }

    return 0;
}
