#include <bits/stdc++.h>
#define task "A"
#define ll long long

const int maxn = 2e3 + 7;
int n, m;
bool a[maxn][maxn];

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    //std::freopen(task".inp", "r", stdin);
    //std::freopen(task".out", "w", stdout);

    std::cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int u, v;
        std::cin >> u >> v;
        a[u][v] = a[v][u] = 1;
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++)
            std::cout << a[i][j] << " ";
        std::cout << "\n";
    }

    return 0;
}
