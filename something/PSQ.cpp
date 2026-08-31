#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
const int oo = 111111111;

struct tree{
    int Min, Max, val;
    tree(){};
    tree(int _Min, int _Max, int _val){Min = _Min, Max = _Max, val = _val;}
};

tree st[4 * N];
int n, a[N + 5], m;

tree merge(tree x, tree y){
    return tree(min(x.Min, y.Min), max(x.Max, y.Max), max(y.Max - x.Min, max(x.val, y.val)));
}

void buildTree(int id, int l, int r){
    if (l == r){
        st[id].Min = min(a[l], a[l - 1]);
        st[id].Max = a[r];
        st[id].val = a[r] - a[l - 1];
        return ;
    }

    int mid = (l + r) / 2;
    buildTree(id * 2, l, mid);
    buildTree(id * 2 + 1, mid + 1, r);

    st[id] = merge(st[id * 2], st[id * 2 + 1]);
}

tree get(int id, int l, int r, int x, int y){
    if (r < x || y < l) return tree(oo, -oo, -oo);
    if (x <= l && r <= y) return st[id];

    int mid = (l + r) / 2;
    return merge(get(id * 2, l, mid, x, y), get(id * 2 + 1, mid + 1, r, x,y));
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);


    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        a[i] += a[i - 1];
    }

    buildTree(1, 1, n);

    while (m--){
        int x, y;
        cin >> x >> y;
        cout << get(1, 1, n, x, y).val << "\n";
    }
}
