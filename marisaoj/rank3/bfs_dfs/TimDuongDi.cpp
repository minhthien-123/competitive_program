#include <bits/stdc++.h>
#define task ""
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

const int maxn = 1e5 + 7;

int n, m;
int par[maxn];
bool vis[maxn];
std::vector<int> adj[maxn], ans;

void bfs(int s) {
    memset(par, -1, sizeof par);

    std::queue <int> q;
    q.push(s);
    vis[s] = true;

    while (!q.empty()) {
        int t = q.front();
        q.pop();
        for (int v : adj[t]) {
            if (!vis[v]) {
                par[v] = t;
                vis[v] = true;
                q.push(v);
            }
        }
    }
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

	bfs(1);

	for (int i = n; i != -1; i = par[i])
		ans.pb(i);

	std::reverse(ans.begin(), ans.end());

	std::cout << ans.size() << "\n";
	for (int i : ans)
		std::cout << i << " ";

	return 0;
}