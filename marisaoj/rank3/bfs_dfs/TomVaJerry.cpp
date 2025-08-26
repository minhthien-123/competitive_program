#include <bits/stdc++.h>
#define task ""
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

const int maxn = 1e5 + 7;
const int inf  = 1e9;

int n, m, a, b, ans = 0;
std::vector<int> adj[maxn];
std::vector<int> d1(maxn, inf), dn(maxn, inf);

void bfs(int s, std::vector<int>& d){
	std::queue<int> q;
	q.push(s);
	d[s] = 0;

	while (q.size()){
		int t = q.front();
		q.pop();

		for (int v : adj[t])
			if (d[v] == inf){
				d[v] = d[t] + 1;
				q.push(v);
			}
	}
}

signed main(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0);

	//std::freopen(task".inp", "r", stdin);
	//std::freopen(task".out", "w", stdout);

	std::cin >> n >> m >> a >> b;

	for (int i = 1; i <= m; i++){
		int u, v;
		std::cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	bfs(a, d1);
	/*for (int i = 1; i <= n; i++)
		std::cout << d1[i] << " ";
	std::cout << "\n";*/
	bfs(b, dn);
	/*for (int i = 1; i <= n; i++)
		std::cout << dn[i] << " ";
	std::cout << "\n";*/

	for (int i = 1; i <= n; i++)
		if (d1[i] <= dn[i] && d1[i] != inf)
			ans++;

	std::cout << ans;

	return 0;
}