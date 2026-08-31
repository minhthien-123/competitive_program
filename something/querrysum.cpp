#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll maxN = 1e5;

char s;
ll n, m, a, b;
ll st[maxN * 4];

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

    st[id] = st[id * 2] + st[id * 2 + 1];
}

ll get(ll id, ll l, ll r, ll u, ll v) {
    if (v < l || r < u) {
        return 0;
    }
    if (u <= l && r <= v) {
        return st[id];
    }
    ll mid = (l + r) / 2;
    return get(id*2, l, mid, u, v) + get(id*2 + 1, mid+1, r, u, v);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("querysum.inp", "r", stdin);
    freopen("querysum.out", "w", stdout);

    cin >> n >> m;
    while (m--){
        cin >> s >> a >> b;
        if (s == 'S') update(1, 1, n, a, b);
        else          cout << get(1, 1, n, a, b) << "\n";
    }
}
