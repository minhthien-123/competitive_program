#include <bits/stdc++.h>
#define task ""
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

const int maxn = 1e5 + 7;

std::vector<int> adj[maxn];
bool vis[maxn];
int n, m, ans = 0;

void dfs(int u){
    vis[u] = true;

    for (int v : adj[u])
        if (!vis[v])
            dfs(v);
}

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    //std::freopen(task".inp", "r", stdin);
    //std::freopen(task".out", "w", stdout);

    std::cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int u, v;
        std::cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    memset(vis, false, sizeof vis);

    for (int i = 1; i <= n; i++){
        if (!vis[i]){
            dfs(i);
            ans++;
        }
    }

    std::cout << ans;

    return 0;
}
