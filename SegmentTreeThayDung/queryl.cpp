#include <bits/stdc++.h>
#define task "queryl"
#define ll long long

const ll maxn = 1e5 + 5;
const ll inf  = 1e9 + 7;

ll n, m, a[maxn], st[4 * maxn];

void update(ll id, ll l, ll r, ll i, ll v) {
    if (i < l || r < i) {
        return ;
    }
    if (l == r) {
        st[id] = v;
        return ;
    }

    ll mid = (l + r) / 2;
    update(id*2, l, mid, i, v);
    update(id*2 + 1, mid+1, r, i, v);

    st[id] = std::max(st[id * 2], st[id * 2 + 1]);
}

ll get(ll id, ll l, ll r, ll u, ll v){
    if (v < l || r < u) return -inf;
    if (u <= l && r <= v) return st[id];

    ll mid = l + r >> 1;
    ll get1 = get(id * 2, l, mid, u, v);
    ll get2 = get(id * 2 + 1, mid + 1, r, u, v);
    return std::max(get1, get2);
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    //std::freopen(task".inp", "r", stdin);
    //std::freopen(task".out", "w", stdout);

    std::cin >> n >> m;
    while(m--){
        ll i, k;
        char type;
        std::cin >> type >> i >> k;
        if (type == 'S'){
            update(1, 1, n, i, k);
        }else
            std::cout << get(1, 1, n, i, k) << "\n";
    }

    return 0;
}
