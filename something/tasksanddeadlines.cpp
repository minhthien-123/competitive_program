#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct val{
    ll a, d;
};

bool cmp(val x, val y){
    return x.a < y.a;
}

val a[1000005];
ll n, tmp = 0, ans = 0;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (ll i = 0; i < n; i++) cin >> a[i].a >> a[i].d;
    sort(a, a + n, cmp);

    for (ll i = 0; i < n; i++){
        tmp += a[i].a;
        ans += a[i].d - tmp;
    }

    cout << ans;

    return 0;
}
