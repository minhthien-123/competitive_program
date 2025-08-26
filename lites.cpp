#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5;

int n, m, q, x, y;
int a[maxn + 5], st[maxn * 4];


void update(int id, int l, int r, int x, int y){
    if (r <= x || y <= l || r <= l) return;
    if (x <= l && r <= y){
        a[id]++;
        st[id] = r - l - st[id];
        return ;
    }

    int mid = (l + r) / 2;

    update(id * 2 + 1, l, mid, x, y);
    update(id * 2 + 2, mid, r, x, y);

    st[id] = st[id * 2 + 1] + st[id * 2 + 2];
    if (a[id] % 2 == 1) st[id] = r - l - st[id];
}

int get(int id, int l, int r, int x, int y){
    if (r <= x || r <= l || y <= l) return 0;
    if (x <= l && r <= y) return st[id];

    int mid = (l + r) / 2;

    int res = get(id * 2 + 1, l, mid, x, y) + get(id * 2 + 2, mid, r, x, y);

    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("lites.inp", "r", stdin);
    freopen("lites.out", "w", stdout);

    cin >> n >> m;
    while (m--){
        cin >> q >> x >> y;
        if (q == 0) update(0, 0, n, x - 1, y);
        else        cout << get(0, 0, n, x - 1, y) << "\n";
    }

    return 0;
}

// l r x y
// x y l r
// x l r y
