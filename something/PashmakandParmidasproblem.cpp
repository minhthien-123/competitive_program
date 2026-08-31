#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;

int n, l[N + 5], r[N + 5], a[N + 5], st[N * 4];
long long ans = 0;
map<int, int> m;

void update(int id, int l, int r, int k){
    if(r < k || k < l)return;
    if(l == r && r == k){
        st[id]++;
        return;
    }
    int mid = (l + r) / 2;
    update(2 * id, l, mid, k);
    update(2 * id + 1, mid + 1, r ,k);
    st[id] = st[id * 2] + st[id * 2 + 1];
}

int get(int id, int l, int r, int x, int y){
    if(x > y)            return 0;
    if(r < x || y < l)   return -1;
    if(x <= l && r <= y) return st[id];

    int mid = (l + r) / 2;
    int left = get(2 * id, l, mid, x, y);
    int right= get(2 * id + 1, mid + 1, r, x, y);
    if(left  < 0) return right;
    if(right < 0) return left;
    return left + right;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];

    for(int i = 0; i < n; i++){
        m[a[i]]++;
        l[i] = m[a[i]];
    }
    m.clear();
    for(int i = n - 1; i >= 0; i--){
        m[a[i]]++;
        r[i] = m[a[i]];
    }
    for(int i = n - 1; i > 0; i--){
        update(1, 1, n, r[i]);
        ans += get(1, 1, n, 1, l[i - 1] - 1);
    }
    cout << ans;
    return 0;
}
