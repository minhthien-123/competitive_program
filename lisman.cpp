#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll N = 1e5;

ll st[N * 4], n, q, x, k, a[N + 5];

void buildTree(ll id, ll l, ll r){
    if (l == r){
        st[id] = a[l];
        return ;
    }

    ll mid = (l + r) / 2;

    buildTree(id * 2, l, mid);
    buildTree(id * 2 + 1, mid + 1, r);

    st[id] = max(st[id * 2], st[id * 2 + 1]);
    if (st[id] < 0) st[id] = 0;
}

void update(ll id, ll l, ll r, ll x, ll k) {
    if (x < l || r < x) return;
    if (l == r) {
        st[id] = k;
        return;
    }

    ll mid = (l + r) / 2;
    update(id * 2, l, mid, x, k);
    update(id * 2 + 1, mid + 1, r, x, k);

    st[id] = max(st[id * 2], st[id * 2 + 1]);
    if (st[id] < 0) st[id] = 0;
}

ll get(ll id, ll l, ll r, ll x, ll y){
    if (y < l || r < x)   return LLONG_MIN;
    if (x <= l && r <= y) return st[id];
    int mid = (l + r) / 2;
    return max(get(id * 2, l, mid, x, y), get(id * 2 + 1, mid + 1, r, x, y));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("lisman.inp", "r", stdin);
    freopen("lisman.out", "w", stdout);

    cin >> n >> q;
    for (ll i = 1; i <= n; i++) cin >> a[i];

    buildTree(1, 1, n);

    while (q--){
        char s;
        cin >> s;

        if (s == 'S'){
            cin >> x >> k;
            update(1, 1, n, x, k);
        }else{
            cout << get(1, 1, n, 1, n) << "\n";
        }

    }

    return 0;
}

