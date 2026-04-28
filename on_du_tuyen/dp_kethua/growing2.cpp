#include <bits/stdc++.h>
#define task "growing2"
#define ll long long

const ll maxn = 507;

ll n, m, d;
ll a[maxn][maxn], pre[maxn][maxn];

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen(task".inp", "r", stdin);
    std::freopen(task".out", "w", stdout);

    std::cin >> n >> m >> d;

    while(d--){
        ll l, r, u, v, k;
        std::cin >> l >> r >> u >> v >> k;
        a[l][u] += k;
        a[l][v + 1] -= k;
        a[r + 1][u] -= k;
        a[r + 1][v + 1] += k;
    }

    for (ll i = 1; i <= n; i++)
        for (ll j = 1; j <= m; j++)
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + a[i][j];

    for (ll i = 1; i <= n; i++){
        for (ll j = 1; j <= m; j++)
            std::cout << pre[i][j] << " ";
        std::cout << "\n";
    }

    return 0;
}
