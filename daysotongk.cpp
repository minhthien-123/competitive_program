#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

struct SegmentTree{
    int left, right;
    int sum, prefix_min, suffix_min, tag;
} st[N * 4];

int n, m, q, a[N];

void build(int id, int l, int r){
    st[id].left = l;
    st[id].right = r;
    if (l == r){
        st[id].sum = a[l];
        st[id].prefix_min = a[l];
        st[id].suffix_min = a[l];
        st[id].tag = 0;
        return;
    }

    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    st[id].sum = st[2 * id + 1].sum + st[2 * id].sum;
    st[id].prefix_min = min(st[2 * id].prefix_min, st[id * 2].sum + st[id * 2 + 1].prefix_min);
    st[id].suffix_min = min(st[2 * id + 1].suffix_min, st[id * 2 + 1].sum + st[id * 2].suffix_min);
    st[id].tag = 0;
}

void down(int id){
    if (st[id].tag != 0){
        st[id * 2].sum += (st[id * 2].right - st[id * 2].left + 1) * st[id * 2].tag;
        st[id * 2].prefix_min += st[id].tag;
        st[id * 2].suffix_min += st[id].tag;
        st[id * 2].tag += st[id].tag;

        st[id * 2 + 1].sum += (st[id * 2 + 1].right - st[id * 2 + 1].left + 1) * st[id * 2 + 1].tag;
        st[id * 2 + 1].prefix_min += st[id].tag;
        st[id * 2 + 1].suffix_min += st[id].tag;
        st[id * 2 + 1].tag += st[id].tag;
    }
}

void update(int id, int l, int r, int v){
    if (l <= st[id].left && st[id].right <= r){
        st[id].sum += (st[id].right - st[id].left + 1) * v;
        st[id].prefix_min += v;
        st[id].suffix_min += v;
        st[id].tag += v;
        return;
    }

    down(id);
    int mid = (st[id].left + st[id].right) / 2;
    if (l <= mid) update(id * 2, l, mid, v);
    if (r > mid) update(id * 2 + 1, mid + 1, r, v);

    st[id].sum = st[id * 2].sum + st[id * 2 + 1].sum;
    st[id].prefix_min = min(st[id * 2].prefix_min, st[id * 2 + 1].prefix_min + st[id * 2].sum);
    st[id].suffix_min = min(st[id * 2 + 1].suffix_min, st[id * 2].suffix_min + st[id * 2 + 1].sum);
}

int get(int id, int l, int r, int k){
    int left = l, right = r;
    int sum = st[id].sum, prefix_min = st[id].prefix_min, suffix_min = st[id].suffix_min;
    while (st[id].left < st[id].right){
        down(id);
        int mid = (st[id].left + st[id].right) / 2;
        if (sum == k) break;
        else if (sum < k){
            left = mid + 1;
            id = id * 2 + 1;
            sum += st[id].sum;
            suffix_min = min(suffix_min, sum + st[id].suffix_min);
        }else{
            right = mid - 1;
            id = id * 2;
            sum += st[id].sum;
            prefix_min = min(prefix_min, sum + st[id].prefix_min);

        }
    }

    if (sum != k) return -1;

    while (st[id].left < st[id].right){
        down(id);
        int mid = (st[id].left + st[id].right) / 2;
        if (st[id * 2].suffix_min + suffix_min == k){
            id = id * 2;
            suffix_min = min(suffix_min, st[id].suffix_min);
        }else{
            id = id * 2 + 1;
            prefix_min = min(prefix_min, st[id * 2].sum + suffix_min + st[id].prefix_min);
            suffix_min += st[id].sum;
        }
    }

    return left;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;


    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);

    while (m--){
        cin >> q;
        if (q == 1){
            int i, v;
            cin >> i >> v;
            update(1, i, i, v);
        }else{
            int l, r, k;
            cin >> l >> r >> k;
            int res = get(1, l, r, k);
            if (res != -1) cout << res << " " << res << "\n";
            else           cout << "-1\n";
        }
    }
}
