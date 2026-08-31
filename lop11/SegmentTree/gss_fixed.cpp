#include <bits/stdc++.h>
using namespace std;

#define oo 1111111111

const int N = 1e5;

struct tree{
    int Min, Max, val;
};

tree merge(tree x, tree y)
{
    tree res;
    res.Min = std::min(x.Min, y.Min);
    res.Max = std::max(x.Max, y.Max);
    res.val = std::max({x.val, y.val, y.Max - x.Min});

    return res;
}

tree st[4 * N];
int n, a[N + 5], m, x, y;

void build(int id, int l, int r){
    if(l == r){
        st[id].Min = a[l - 1];
        st[id].Max = a[r];
        st[id].val = a[r] - a[l - 1];
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    st[id] = merge(st[id * 2], st[id * 2 + 1]);
}

tree get(int id, int l, int r, int x, int y){
    if(x > r || y < l)   return {oo, -oo, -oo};
    if(x <= l && r <= y) return st[id];
    int mid = (l + r) / 2;
    return merge(get(id * 2, l, mid, x, y), get(id * 2 + 1, mid + 1, r, x, y));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("gss.inp", "r", stdin);
    freopen("gss.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        a[i] += a[i - 1];
    }

    build(1, 1, n);

    cin >> m;
    while (m--){
        cin >> x >> y;
        cout << get(1, 1, n, x , y).val << "\n";
    }
}

/*
    a[r] - a[l - 1]
*/