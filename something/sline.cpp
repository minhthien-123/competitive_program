#include <bits/stdc++.h>
using namespace std;

struct sline{
    long long val;
    long long dex;
};

bool ss(sline x, sline y){
    if (x.val < y.val) return(true);
    if (x.val == y.val && x.dex < y.dex) return(true);
    return false;

}

long long n, i, beg, en, mx;
sline a[1000005];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("sline.inp", "r", stdin);
    freopen("sline.out", "w", stdout);

    cin >> n;
    for (i = 0; i < n; i++) cin >> a[i].val >> a[i].dex;

    sort(a, a + n, ss);

    beg = a[0].val;
    en  = a[0].dex;
    mx  = en - beg;

    //for (i = 0; i < n; i++) cout << a[i].val << " " << a[i].dex << "\n";

    //cout << "\n";

    for (i = 1; i < n; i++){
        //cout << a[i].dex << " " << a[i + 1].val << " ";
        if (en >= a[i].val) {
            en = max(en, a[i].dex);
            //cout << mx << " ";
            //cout << 1 << " ";
        }else{
            mx = max(mx, en - beg);
            beg = a[i].val;
            en = a[i].dex;

            //cout << 2 << " ";
        }

        //cout << beg << " " << en << "\n";
    }

    cout << max(mx, en - beg);

}
