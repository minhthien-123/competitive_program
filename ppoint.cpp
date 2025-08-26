#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct data{
    ll dex, col;
};

bool cmp(data x, data y){
    return x.dex < y.dex;
}

ll n;
data a[1000005];

int main(){q
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("ppoint.inp", "r", stdin);
    freopen("ppoint.out", "w", stdout);

    cin >> n;
    for (ll i = 1; i <= n; i++) cin >> a[i].dex >> a[i].col;

    sort(a + 1, a + n + 1, cmp);
    for (ll i = 1; i <= n; i++) cout << a[i].dex << " " << a[i].col << "\n";
}
