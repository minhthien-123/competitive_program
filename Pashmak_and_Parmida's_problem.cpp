#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;

int n, l[N + 5], r[N + 5], st[N * 4], a[N + 5];
long long ans = 0;
map<int, int> m;

void update(int id, int l, int r, int k){
    if (r < k || k < l) return;
    if (l == r == s){
        st[id]++;
        return;
    }
    int mid = (l + r) / 2;
    update(id * 2, l, mid, k);
    update(id * 2 + 1, mid + 1, r, k);
    st[id] = st[id * 2] + st[id + 2 + 1];
}

int get(int id, int l, int r, int x, int y){
    if (x > y) return 0;
    if (y < l || r < x) return -1;
    if (x <= l && r <= y) return st[id];
    int mid = (l + r) / 2;
    int left = get(id * 2, l, mid, x, y), right = get(id * 2 + 1, mid + 1, r, x, y);
    if (min(left, right) < 0) return max(left, right);
    else                      return left + right;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        m[a[i]]++;
        l[i] = m[a[i]];
    }
    m.clear();
    for (int i = n; i > 0; i--){
        m[a[i]]++;
        r[i] = m[a[i]];
    }

    for (int i = n; i > 0; i--){
        update(1, 1, n, r[i]);
        ans += get(1, 1, n, 1, l[i - 1] - 1);
    }

    cout << ans;
}
