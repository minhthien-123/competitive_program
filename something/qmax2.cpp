#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

struct tree{
    int lazy, val;
};

int n, m;
tree st[N * 4];

void down(int id){
    int t = st[id].lazy;

    st[id * 2].lazy += t;
    st[id * 2].val  += t;

    st[id * 2 + 1].lazy += t;
    st[id * 2 + 1].val  += t;

    st[id].lazy = 0;
}

void update(int id, int l, int r, int u, int v, int k){
    if (r < u || v < l) return;
    if (l >= u && v >= r){
        st[id].lazy += k;
        st[id].val  += k;
        return ;
    }

    int mid = (l + r) / 2;

    down(id);

    update(id * 2, l, mid, u, v, k);
    update(id * 2 + 1, mid + 1, r, u, v, k);

    st[id].val = max(st[id * 2].val, st[id * 2 + 1].val);
}

int get(int id, int l, int r, int u, int v){
    if (r < u || v < l) return 0;
    if (l >= u && v >= r) return st[id].val;

    int mid = (l + r)/ 2;

    down(id);

    return max(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //freopen("qmax2.inp", "r", stdin);
    //freopen("qmax2.out", "w", stdout);

    cin >> n >> m;
    while (m--){
        int q;
        cin >> q;
        if (q == 0){
            int l, r, k;
            cin >> l >> r >> k;
            update(1, 1, n, l, r, k);
        }else{
            int l, r;
            cin >> l >> r;
            cout << get(1, 1, n, l, r);
        }
    }
}

//6 3
//0 1 3 3
//0 4 6 4
//1 1 6
