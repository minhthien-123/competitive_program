#include <bits/stdc++.h>
using namespace std;

struct arr{
    string color;
    long long val;
    bool kt;
};

struct ans{
    long long beg, en;
};

arr a;
ans res;
long long n, i, j, d, s;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cou.tie(0);

    freopen("interval.inp", "r", stdin);
    freopen("interval.out", "w", stdout);

    cin >> n;

    for (i = 0; i < 2 * n; i++){
        cin >> a[i].color >> a[i].val;
        a[i].kt = false;
    }

    i = 0; j = 1;
    s = 0; d = 0;
    while (d <= n){
        if (a[i].kt == false && a[j].kt == false && a[i].color != a[j].color){
            d++;
            s += j - i;
            res[d].beg = i;
            res[d].en  = j;
            i++;
        }else j++;
    }

    cout << s;


    return 0;
}
