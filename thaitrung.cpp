#include <bits/stdc++.h>
#define int long long
#define range(i, l, r) for(int i = l; i <= r; ++i)
using namespace std;

const int N = 1e6 + 9;
const int INF = 1e18;

int n, m;
int a[N], tree[4 * N];
int i, j;
char c[3];

void build(int id, int l, int r) {
    if (l == r) {
        tree[id] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
    tree[id] = min(tree[2 * id], tree[2 * id + 1]);
}

void update(int id, int l, int r, int pos, int val) {
    if (l == r) {
        tree[id] = val;
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) {
        update(2 * id, l, mid, pos, val);
    } else {
        update(2 * id + 1, mid + 1, r, pos, val);
    }
    tree[id] = min(tree[2 * id], tree[2 * id + 1]);
}

int get(int id, int l, int r, int u, int v) {
    if (l > v || r < u) {
        return INF; // Out of range, return INF
    }
    if (l >= u && r <= v) {
        return tree[id]; // Fully within range
    }
    int mid = (l + r) / 2;
    return min(get(2 * id, l, mid, u, v), get(2 * id + 1, mid + 1, r, u, v));
}

void solve() {
    cin >> n >> m;
    build(1, 1, n);

    while (m--) {
        cin >> c >> i >> j;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
