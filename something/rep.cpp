#include <bits/stdc++.h>
using namespace std;

struct thiendeptrai{
    long long beg, en;
};

bool ss(thiendeptrai x, thiendeptrai y){
    if (x.beg <= y.beg && x.en <= y.en) return true;
    else if (x.beg == y.beg && x.en < y.en) return true;
    return false;
}

thiendeptrai a[1000005];
long long i, n, d, ans[1000005], beg_n, end_n, x;
map<long long, long long> m;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("rep.inp", "r", stdin);
    freopen("rep.out", "w", stdout);

    cin >> n;
    for (i = 0; i < n; i++){
        cin >> a[i].beg >> a[i].en;
    }

    sort(a, a + n, ss);
    d = 0;

    for (i = 0; i < n; i++) cout << a[i].beg << " " << a[i].en << "\n";
    cout << "\n";

    ans[0] = a[i].en;
    ans[1] = a[i].en - 1;
    d = 1;

    for (i = 1; i < n; i++){
        if (a[i].beg == a[i - 1].en){
            ans[++d] = a[i].beg;
            ans[++d] = a[i].beg - 1;
            ans[++d] = a[i].beg + 1;
        }else if (a[i].beg > a[i - 1].en){
            ans[++d] = a[i].beg;
            ans[++d] = a[i].beg - 1;
        }else{
            ans[++d] = a[i].en;
            ans[++d] = a[i].en + 1;
        }
    }

    for (int i = 0; i <= d; i++)
        cout << ans[i] << " ";

    return 0;
}
