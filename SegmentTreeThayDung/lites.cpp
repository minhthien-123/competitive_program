#include <bits/stdc++.h>
#define ll long long

const ll maxn = 1e5;

ll st[maxn * 4], a[maxn * 4], n, s, e, i, m, q;

void update(ll id, ll l, ll r, ll x, ll y) {
    if(r <= l || r <= x || y <= l) return;
    if(x <= l && r <= y){
        a[id]++;
        st[id] = r - l - st[id];
        return;
    }

    ll mid = (l + r) / 2;

    update(2 * id + 1, l, mid, x, y);
    update(2 * id + 2, mid, r, x, y);

    st[id] = st[2 * id + 1] + st[2 * id + 2];
    if(a[id] % 2 == 1) st[id] = r - l - st[id];
}

ll get(ll id, ll l, ll r, ll x, ll y){
    if(r <= l || r <= x || y <= l) return 0;
    if(x <= l && r <= y)           return st[id];

    ll mid = (l + r) / 2;

    ll ans = get(2 * id + 1, l, mid, x, y) + get(2 * id + 2, mid, r, x, y);

    if (a[id] % 2 == 1) ans = std::min(r, y) - std::max(l, x) - ans;

    return ans;
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen("lites.inp", "r", stdin);
    std::freopen("lites.out", "w", stdout);

    std::cin >> n >> m;
    while (m --){
        std::cin >> q >> s >> e;
        if (q == 0) update(0, 0, n, s - 1, e);
        else        std::cout << get(0, 0, n, s - 1, e) << "\n";
    }

    return 0;
}

