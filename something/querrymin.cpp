#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll N = 1e5;

ll n, m, a, b;
ll st[4 * N];
string s;

void update(ll id, ll l, ll r, ll i, ll v){
    if (i < l || r < i) return;
    if (l == r) {
        st[id] = v;
        return;
    }

    ll mid = (l + r) / 2;
    update(2 * id, l, mid, i, v);
    update(2 * id + 1, mid + 1, r, i, v);

    if (st[id * 2] <= 0 && st[id * 2 + 1] <= 0) st[id] = 0;
    else if (st[id * 2] <= 0 || st[id * 2 + 1] <= 0)
            st[id] = max(st[id * 2], st[id * 2 + 1]);
    else st[id] = min(st[id * 2], st[id * 2 + 1]);

    if (st[id] < 0) st[id] = 0;
}

ll get(ll id, ll l, ll r, ll i, ll j){
    if (j < l && r < i)    return LLONG_MIN;
    if (i <= l && r <= j)  return st[id];

    ll mid = (l + r) / 2;
    return min(get(id * 2, l, mid, i, j), get(id * 2 + 1, mid + 1, r, i, j));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("querrymin.inp", "r", stdin);
    freopen("querrymin.out", "w", stdout);

    cin >> n >> m;
    while (m--){
        cin >> s;
        if (s[0] == 'A'){
            cin >> a >> b;
            update(1, 1, n, a, b);
        }
        else cout << get(1, 1, n, 1, n) << "\n";

        //for (ll i = 0; i < 4 * n; i++) cout << st[i] << " ";
        //cout << "\n";
    }
}
