#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;

int n, a[N + 4], st[4 * N], k;


void buildTree(int id, int l, int r){
    if (l == r){
        st[id] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    buildTree(id * 2, l, mid);
    buildTree(id * 2 + 1, mid + 1, r);

    st[id] = st[id * 2] + st[id * 2 + 1];
}

int get(int id, int l, int r, int x, int y){
    if (y < l || r < x) return INT_MIN;
    if (l >= x && r <= y) return st[id];

    int mid = (l + r) / 2;
    return max(get(id * 2, l, mid, x, y), get(id * 2 + 1, mid + 1, r, x, y));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("summax.inp", "r", stdin);
    freopen("summax.out", "w", stdout);

    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        //a[i] += a[i - 1];
    }

    buildTree(1, 1, n);

    //for (int i = 1; i <= 4 * n; i++) cout << st[i] << " ";
    //cout << "\n";

    int ans = INT_MIN;
    for (int i = 0; i <= n; i++) ans = max(ans, get(1, 1, n, i, i + k - 1));

    cout << ans;
}
