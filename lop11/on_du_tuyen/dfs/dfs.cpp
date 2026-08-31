#include <bits/stdc++.h>
#define task "dfs"
#define ll long long
#define pb push_back

const int maxn = 1e5 + 7;

std::vector<int> adj[maxn], res;
bool vis[maxn];
int par[maxn];
int m, n, s, t;

void solve(int u){
    if (u == par[u]){
        res.pb(u);
        return ;
    }

    res.pb(u);
    solve(par[u]);
}

void dfs(int u){
    vis[u] = true;
    if (u == t){
        solve(t);
        return;
    }

    for (int v : adj[u]){
        if (!vis[v]){
            par[v] = u;
            dfs(v);
        }
    }
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen(task".inp", "r", stdin);
    std::freopen(task".out", "w", stdout);

    std::cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++){
        int u, v;
        std::cin >> u >> v;
        adj[u].pb(v);
        //adj[v].pb(u);
    }

    for (int i = 1; i <= n; i++)
        std::sort(adj[i].begin(), adj[i].end());

    par[s] = s;
    dfs(s);

    std::reverse(res.begin(), res.end());

    for (int i : res)
        std::cout << i << " ";

    return 0;
}
