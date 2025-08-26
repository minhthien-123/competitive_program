#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll n, t, ans = LLONG_MAX;
string s;
vector<long long> l, q, d;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("llqqdd.inp", "r", stdin);
    freopen("llqqdd.out", "w", stdout);

    cin >> n >> t;
    cin >> s;

    for (ll i = 0; i < n; i++){
        if (s[i] == 'L') l.push_back(i);
        else if (s[i] == 'Q') q.push_back(i);
        else if (s[i] == 'D') d.push_back(i);
    }

    /*for (ll i = 0; i < l.size(); i++) cout << l[i] << " ";
    cout << "\n";
    for (ll i = 0; i < q.size(); i++) cout << q[i] << " ";
    cout << "\n";
    for (ll i = 0; i < d.size(); i++) cout << d[i] << " ";
    cout << "\n";*/

    ll i = 0, j = 0, k = 0;;
    while (i <= l.size() - t){
        ll tmp = l[i + t - 1];
        while (q[j] < tmp && j <= q.size() - t) j++;
        if (q[j] < tmp) break;
        tmp = q[j + t - 1];
        while (d[k] < tmp && k <= d.size() - t) k++;
        if (d[k] < tmp) break;
        tmp = d[k + t - 1];
        //cout << tmp << " " << l[i] << " " << tmp - l[i] << "\n";
        ans = min(ans, tmp - l[i] + 1);
        i++;
    }
    cout << ans - 3 * t;

    return 0;
}
