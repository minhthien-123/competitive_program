#include <bits/stdc++.h>
#define task ""
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

const int maxn = 1e5 + 7;

int n, m;
std::vector<int> adj[maxn];
int a[maxn];

bool bfs(int s){
	std::queue<int> q;
	q.push(s);
	a[s] = 0;

	while (q.size()){
		int t = q.front();
		q.pop();

		for (int v : adj[t])
			if (a[v] == -1){
				a[v] = 1 - a[t];
				q.push(v);
			}else if (a[v] == a[t]){
				return false;
			}
	}

	return true;
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

	memset(a, -1, sizeof a);

	for (int i = 1; i <= n; i++){
		if (a[i] == -1){
			if (!bfs(i)){
				std::cout << "NO";
				return 0;
			}
		}
	}

	std::cout << "YES";

	return 0;
}