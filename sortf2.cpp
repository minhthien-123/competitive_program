#include <bits/stdc++.h>
using namespace std;

struct num{
    int val;
    int dex;
};

int n, m, ai = 0, bi = 0;
num a[100005], b[100005];

bool ss1(num x, num y){
    if (x.val == y.val) return x.dex < y.dex;
    else                return x.val < y.val;
}

bool ss(num x, num y){
    if (x.val == y.val) return x.dex < y.dex;
    else                return x.val > y.val;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("sortf2.inp", "r", stdin);
    freopen("sortf2.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> m;
        if (m % 2 == 0){
            a[ai].val = m;
            a[ai].dex = i;

            ai ++;
        }else{
            b[bi].val = m;
            b[bi].dex = i;

            bi++;
        }
    }

    sort(a, a + ai, ss1);
    sort(b, b + bi, ss);

    for (int i = 0; i < ai; i++) cout << a[i].dex + 1 << " ";
    for (int i = 0; i < bi; i++) cout << b[i].dex + 1 << " ";


    return 0;
}
