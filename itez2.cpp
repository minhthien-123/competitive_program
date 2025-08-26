#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

int n, m, x, y, q, a[N + 5], st[4 * N];

void update(int id, int l, int r, int x, int y){
    if (x < l || x > r) return;

    if (l == r){
        st[id] = y;
        return;
    }

    int mid = (l + r) / 2;
    update(id * 2, l, mid, x, y);
    update(id * 2 + 1, mid + 1, r, x, y);

    st[id] = st[id * 2] + st[id * 2 + 1];
}

int get(int id, int l, int r, int x, int y){
    if (y < l || r < x) return 0;
    if (l >= x && r <= y) return st[id];

    int mid = (l + r) / 2;
    return get(id * 2, l, mid, x, y) + get(id * 2 + 1, mid + 1, r, x, y);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //freopen("itez2.inp", "r", stdin);
    //freopen("itez2.out", "w", stdout);

    cin >> n >> m;
    while (m--){
        cin >> q >> x >> y;
        if (q == 1) update(1, 1, n, x, y);
        else        cout << get(1, 1, n, x, y) << "\n";
    }

    return 0;
}
