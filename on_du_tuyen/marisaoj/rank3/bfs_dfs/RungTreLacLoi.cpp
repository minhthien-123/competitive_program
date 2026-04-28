#include <bits/stdc++.h>
#define task "bfs_dfs"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5 + 7;
int n, m, a, b, ans = LLONG_MAX;
int d1[maxn], d2[maxn];
std::vector<int> adj[maxn];

void bfs(int s, int d[]){
    d[s] = 0;
    std::queue<int> q;
    q.push(s);

    while (q.size()){
        int t = q.front();
        q.pop();

        for (int v : adj[t])
            if (d[v] == -1){
                d[v] = d[t] + 1;
                q.push(v);
            }
    }
}

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen(task".inp", "r", stdin);
    std::freopen(task".out", "w", stdout);

    std::cin >> n >> m;
    std::cin >> a >> b;
    while (m--){
        int u, v;
        std::cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    memset(d1, -1, sizeof d1);
    memset(d2, -1, sizeof d2);
    bfs(a, d1);
    bfs(b, d2);

    for (int i = 1; i <= n; i++){
        if (abs(d1[i] - d2[i]) & 1) continue;
        ans = std::min(ans, (d1[i] + d2[i]) / 2);
    }

    if (ans == LLONG_MAX)
        std::cout << -1;
    else
        std::cout << ans;

    return 0;
}

