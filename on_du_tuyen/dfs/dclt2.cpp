#include <bits/stdc++.h>
#define task "dclt2"
#define ll long long
#define pb push_back

const int maxn = 1e5 + 7;

std::vector<int> adj[maxn], res;
bool vis[maxn];
int n, m, ans;

void dfs(int u){
    if (vis[u]) return;
    ans++;
    vis[u] = true;

    for (int v : adj[u])
        if (!vis[v])
            dfs(v);
}

int main(){
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

    for (int i = 1; i <= n; i++){
        ans = 0;
        dfs(i);
        if (ans != 0)
            res.pb(ans);
    }

    std::sort(res.begin(), res.end());

    std::cout << res.size();
    std::cout << "\n";
    for (int x : res)
        std::cout << x << " ";

    return 0;
}
