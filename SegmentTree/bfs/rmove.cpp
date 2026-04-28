#include <bits/stdc++.h>
#define task "rmove"
#define ll long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

const int maxn = 1e4 + 7;

std::vector<int> ans1(maxn, INT_MAX);
std::vector<int> ansn(maxn, INT_MAX);
std::vector<int> adj[maxn];
int n, m;
int res = INT_MAX;

void bfs(int s, std::vector<int> d){
	std::queue<int> q;
	q.push(s);
	d[s] = 0;

	while (q.size()){
		int u = q.front();
		q.pop();

		for (int v : adj[u])
			if (d[v] == INT_MAX){
				d[v] = d[u] + 1;
				q.push(v);
			}
	}
}

int main(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0);

	//std::freopen(task".inp", "r", stdin);
	//std::freopen(task".out", "w", stdout);

	std::cin >> n >> m;
	while (m--){
		int u, v;
		std::cin >> u >> v;
		adj[u].pb(v);
	}

	bfs(1, ans1);
	bfs(n, ansn);

	for (int i = 0; i < ans1.size(); i++)
		if (ans1[i] != INT_MAX && ansn[i] != INT_MAX)
			res = std::min(res, ans1[i] + ansn[i]);

	if (res == INT_MAX)
		res = -1;

	std::cout << res;

	return 0;
}
