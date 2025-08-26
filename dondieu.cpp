#include <bits/stdc++.h>
using namespace std;

long long n, i, res, ans, en, a[1000005], tmp;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("dondieu.inp", "r", stdin);
    freopen("dondieu.out", "w", stdout);

    cin >> n;
    for (i = 0; i < n; i++) cin >> a[i];

    tmp = a[0];
    res = 1;
    ans = LLONG_MIN;
    en = 0;
    for (i = 1; i < n; i++){
        if (a[i] == tmp) res++;
        else{
            if (res > ans){
                en = i;
                ans = res;
            }
            res = 1;
            tmp = a[i];
        }
        //cout << tmp << "\n";
    }

    cout << en - ans<< " " << en;
}
