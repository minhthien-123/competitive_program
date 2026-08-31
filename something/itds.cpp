#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

int a[N + 5], l, r, k, u, v, m, n, q, st[4 * N];


void buildTree(int id, int l, int r){
    if (l == r){
        st[id] = l;
        return;
    }

    int mid = (l + r) / 2;
    buildTree(id * 2, l, mid);
    buildTree(id * 2 + 1, mid + 1, r);

    st[id] = min(st[id * 2], st[id * 2 + 1]);
}

void update(int id, int l, int r, int u, int v){
    if (l == r){
        st[u] = v;
        return;
    }

    int mid = (l + r) / 2;
    update(id * 2, l, mid, u, v);
    update(id * 2 + 1, mid + 1, r, u, v);

    st[id] = min(st[id * 2 + 1], st[id]);
}

int get(int id, int l, int r, int x, int y, int k){
    if (y < l || x > r) return INT_MAX;
    if (l >= x && r <= y) return st[id];

    int mid = (l + r) / 2;
    int ans = INT_MAX;

    int a = get(id * 2, l, mid, x, y, k);
    int b = get(id * 2 + 1, mid + 1, r, x, y, k);

    if (a >= k) ans = a;
    if (b >= k) ans = min(ans, b);

    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("itds.inp", "r", stdin);
    freopen("itds.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];

    buildTree(1, 1, n);

    for (int i = 1; i <= 4 * n; i++) cout << st[i] << " ";

    while(m--){
        cin >> q;
        if (q == 1){
            cin >> u >> v;
            update(1, 1, n, u, v);
        }else{
            cin >> l >> r >> k;
            cout << get(1, 1, n, l, r, k) << "\n";
        }
    }
}
