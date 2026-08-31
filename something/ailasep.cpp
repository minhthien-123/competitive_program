#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct index{
    ll id, val, height;
};

bool cmp(index x, index y){
    return ((x.height < y.height) || (x.height == y.height) && (x.val < y.val));
}

ll n, q, i;
index a[1000005];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("ailasep.inp", "r", stdin);
    freopen("ailasep.out", "w", stdout);

    cin >> n >> q;
    for (i = 1; i <= n; i++){
        cin >> a[i].id >> a[i].val >> a[i].height;
    }

    sort(a + 1, a + n + 1, cmp);

    for (i = 1; i <= n; i++){
        cout << a[i].id << " " << a[i].val << " " << a[i].height << "\n";
    }

    return 0;
}
