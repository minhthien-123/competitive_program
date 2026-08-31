#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll n, m;
ll a[505][505];

ll count9(ll arr[], ll n) {
    ll count = 0, s = 0, mod[9] = {1, 0, 0, 0, 0, 0, 0, 0, 0};
    for (ll i = 0; i < n; i++) {
        s = (s + arr[i] % 9) % 9;
        count += mod[s];
        mod[s]++;
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> m >> n;

    for (ll i = 0; i < m; i++) {
        for (ll j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        ll arr[m] = {0};
        for (ll j = i; j < n; j++) {
            for (ll k = 0; k < m; k++) {
                arr[k] += a[k][j];
            }
            ans += count9(arr, m);
        }
    }

    cout << ans << endl;

    return 0;
}
