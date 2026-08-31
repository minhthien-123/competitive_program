#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool cmp(ll a, ll b){
    return a > b;
}

ll a[1000005];
ll n, m;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (ll i = 1; i <= n; i++) cin >> a[i];
    for (ll i = 1; i <= n; i++){
        ll q;
        cin >> q;
        a[i] = q - a[i];
    }

    sort(a + 1, a + n + 1, cmp);

    //for (int i = 1; i <= n; i++) a[i] += a[i - 1];
    //for (ll i = 1; i <= n; i++) cout << a[i] << " ";
    //cout << "\n";

    ll ans = 0;
    ll val = 0;
    while(a[ans] >= 0) val += a[ans++];

    //cout << ans << " " << val << "\n";

    for (ll i = ans + 1; i <= n; i++) a[i] += a[i - 1];
    for (ll i = ans; i <= n; i++) a[i] = abs(a[i]);
    //for (ll i = 1; i <= n; i++) cout << a[i] << " ";
    //cout << "\n";

    for (ll i = 1; i <= m; i++){
        ll q;
        cin >> q;
        q += val;

        //cout << q << " ";

        ll res = upper_bound(a + ans, a + n + 1, q) - a;

        cout << res - 1<< "\n";
        //ll l = ans, r = n;
        //while (l <= r){
            //if ()
        //}
        //int j = ans;
        //while (j <= n && ) j++;
        //cout << j - 1 << "\n";
    }
}
