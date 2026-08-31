#include <bits/stdc++.h>
using namespace std;

struct arr{
    long long val, dex;
};

bool ss(arr x, arr y){
    if (x.val < y.val) return true;
    return false;
}

arr w[1000005], b[1000005];
string str;
long long n, i, j, d, s, x, k;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("interval.inp", "r", stdin);
    freopen("interval.out", "w", stdout);

    cin >> n;
    i = 0; j = 0;

    for (k = 0; k < 2 * n; k++){
        cin >> str;
        cin >> x;
        if (str == "W"){
            w[i].val = x;
            w[i].dex = k;
            i++;
        }else{
            b[j].val = x;
            b[j].dex = k;
            j++;
        }
    }

    sort(w, w + n, ss);
    sort(b, b + n, ss);

    //for (i = 0; i < n / 2; i++) cout << w[i].val << " " << w[i].dex << "\n";
    //cout << "\n";
    //for (i = 0; i < n / 2; i++) cout << b[i].val << " " << b[i].dex << "\n";

    for (i = 0; i < n; i++) s += abs(w[i].val - b[i].val);

    cout << s << "\n";
    for (i = 0; i < n; i++)
        cout << min(b[i].dex, w[i].dex) + 1 << " " << max(b[i].dex, w[i].dex) + 1 << "\n";
        //cout << b[i] << " " << w[i] << "\n";

    return 0;
}
