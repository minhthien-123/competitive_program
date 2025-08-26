#include <bits/stdc++.h>
#define task "service"
#define int long long

const int inf = 1e9 + 7;
const int maxn = 807;

int d[maxn][maxn], c[maxn][maxn];
int n, m, k, ans = 0;

void solve(){
    for (int u = 1; u <= n; u++)
        for (int v = 1; v <= n; v++)
            d[u][v] = c[u][v];

    for (int p = 1; p <= n; p++)
        for (int u = 1; u <= n; u++)
            for (int v = 1; v <= n; v++)
                if (d[u][v] > d[u][p] + d[p][v])
                    d[u][v] = d[u][p] + d[p][v];
}

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen(task".inp", "r", stdin);
    std::freopen(task".out", "w", stdout);

    std::cin >> n >> m >> k;

    std::cout << n;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++)
            c[i][j] = inf;
        c[i][i] = 0;
    }


    for (int i = 1; i <= m; i++){
        int u, v;
        std::cin >> u >> v >> c[u][v];
    }

    std::cout << n;

    //solve();

    for (int u = 1; u <= n; u++)
        for (int v = 1; v <= n; v++)
            ans += d[u][v];

    std::cout << ans;

    return 0;
}
