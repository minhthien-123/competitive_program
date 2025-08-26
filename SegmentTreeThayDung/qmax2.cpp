#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll N = 1e5;

struct tree{
    ll lazy;
    ll val;
};

tree st[N * 4];
ll n, m, x, y, k, q;

void down(ll id){
    ll t = st[id].lazy;

    st[id * 2].lazy += t;
    st[id * 2].val += t;

    st[id * 2 + 1].lazy += t;
    st[id * 2 + 1].val += t;

    st[id].lazy = 0;
}

void update(ll id, ll l, ll r, ll x, ll y, ll k){
    if (x > r || y < l) return;
    if (l >= x && y >= r){
        st[id].lazy += k;
        st[id].val  += k;
        return;
    }

    ll mid = (l + r) / 2;

    down(id);

    update(id * 2, l, mid, x, y, k);
    update(id * 2 + 1, mid + 1, r, x, y, k);

    st[id].val = max(st[id * 2].val, st[id * 2 + 1].val);
}

ll get(ll id, ll l, ll r, ll x, ll y){
    if (x > r || y < l) return LLONG_MIN;
    if (l >= x && y >= r){
        return st[id].val;
    }

    ll mid = (l + r) / 2;

    down(id);

    return max(get(id * 2, l, mid, x, y), get(id * 2 + 1, mid + 1, r, x, y));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("qmax2.inp", "r", stdin);
    freopen("qmax2.out", "w", stdout);

    cin >> n >> m;
    while(m--){
        cin >> q;
        if (q == 0){
            cin >> x >> y >> k;
            update(1, 1, n, x, y, k);
        }else{
            cin >> x >> y;
            cout << get(1, 1, n, x, y) << "\n";
        }
    }

    return 0;
}
