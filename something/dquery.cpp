#include <bits/stdc++.h>
using namespace std;

struct arr{
    int i, j, type, dex;
};

arr a[1000005];
int n, q, res[1000005], lastpos[1000005], bit[1000005];

void update(int id, int k){
    for (id; id <= n; id += id & (-id)) bit[id] += k;
}

int get(int id){
    int ans = 0;
    for (id; id > 0; id -= id & (-id)) ans += bit[id];

    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //freopen("dquery.inp", "r", stdin);
    //freopen("dquery.out", "w", stdout);

    cin >> n >> q;
    for (int i = 1; i <= n; i++){
        cin >> a[i].i;
        a[i].j = i;
        a[i].type = -1;
    }

    //cin >> q;
    for (int i = 1; i <= q; i++){
        cin >> a[i + n].i >> a[i + n].j;
        a[i + n].dex = i;
    }

    for (int i = 1; i <= n + q; i++){
        if (a[i].type == -1){
            update(a[i].j, 1);
            if (lastpos[a[i].i] > 0) update(lastpos[a[i].i], -1);
            lastpos[a[i].i] = a[i].j;
        }else{
            res[a[i].dex] = get(a[i].j) - get(a[i].i - 1);
        }
    }

    for (int i = 1; i <= q; i++) cout << res[i] << "\n";
}
