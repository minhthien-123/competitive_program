#include <bits/stdc++.h>
using namespace std;

const int MAXN = 400 + 10;
//const long long INF = (long long)(1e15);
#define INF 1e15

int n, m, k;
long long e[MAXN][MAXN],dij;
long long save_e[MAXN][MAXN];

void input() {
    cin >> n >> m >> k;
    for(int i = 1; i <= n + 3; ++i) {
        for(int j = 1; j <= n + 3; ++j)
            e[i][j] = INF;
        e[i][i] = 0;
    }

    for(int i = 1; i <= m; ++i) {
        int u, v; long long c;
        cin >> u >> v >> c;
        e[u][v] = min(e[u][v], c);
    }
}

void intermediate(int k, int l1, int r1, int l2, int r2) {
    for(int i = l1; i <= r1; ++i)
        for(int j = l2; j <= r2; ++j)
            if (e[i][j] > e[i][k] + e[k][j])
                e[i][j] = e[i][k] + e[k][j];
}

void init_floyd() {
    for(int k = 1; k <= n; ++k)
        intermediate(k, 1, n, 1, n);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            save_e[i][j] = e[i][j];
}

long long update_floyd() {
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            e[i][j] = save_e[i][j];

    for(int k = 1; k <= n; ++k) {
        intermediate(k, 1, n, n + 1, n + 3);
        intermediate(k, n + 1, n + 3, 1, n + 3);
    }

    for(int k = n + 1; k <= n + 3; ++k) {
        intermediate(k, 1, n + 3, 1, n + 3);
    }
}

long long get_dij() {
    long long dij = 0;
    for(int i = 1; i <= n + 3; ++i)
        for(int j = 1; j <= n + 3; ++j)
            if ((i != j) && (e[i][j] < INF)) {
                dij += e[i][j];
            }
    return dij;
}

void solve_query() {
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= 3; ++j)
            e[i][n + j] = e[n + j][i] = INF;
    for(int i = 1; i <= 3; ++i) {
        for(int j = 1; j <= 3; ++j)
            e[n + i][n + j] = e[n + j][n + i] = INF;
        e[i][i] = 0;
    }

    int p;
    cin >> p;
    for(int i = 1; i <= p; ++i) {
        int u, v; long long c;
        cin >> u >> v >> c;
        e[u][v] = min(e[u][v], c);
    }

    update_floyd();
    dij = get_dij();
    cout << dij << "\n";
}

int main() {
    freopen("service.inp", "r", stdin);
    freopen("service.out", "w", stdout);
    input();
    init_floyd();
    for(int i = 1; i <= k; ++i)
        solve_query();
}
