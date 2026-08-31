#include <bits/stdc++.h>
#define task ""
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

const int maxn = 1e5 + 7;
std::vector<int> adj[maxn];
int n, m, ans = 0;
int dp[maxn];
bool vis[maxn];

int dfs(int u){
    if(vis[u])
        return dp[u];
    vis[u] = true;
    for(int v : adj[u])
        dp[u] = std::max(dp[u], dfs(v) + 1);
    return dp[u];
}

signed main(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0);

	//std::freopen(task".inp", "r", stdin);
	//std::freopen(task".out", "w", stdout);

    std::cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
    }

    memset(dp, 0, sizeof dp);
    memset(vis, 0, sizeof vis);

    for(int i = 1; i <= n; i++)
        ans = std::max(ans, dfs(i));

    std::cout << ans;

    return 0;
}
