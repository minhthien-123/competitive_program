#include <bits/stdc++.h>
#define task ""
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

const int maxn = 1e5 + 7;

std::vector<int> adj[maxn];
int n, m, d[maxn];
bool vis[maxn];

void bfs(int u){
	std::queue<int> q;
	q.push(u);
	vis[u] = true;

	while (q.size()){
		int t = q.front();
		q.pop();

		for (int v : adj[t])
			if (!vis[v]){
				d[v] = d[t] + 1;
				vis[v] = true;
				q.push(v);
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

	for (int i = 2; i <= n; i++){
		if (!d[i]) d[i] = -1;
		std::cout << d[i] << " ";
	}

	return 0;
}