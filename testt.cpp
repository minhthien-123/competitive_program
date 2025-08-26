#include <bits/stdc++.h>
#define task "JzzhuandCities"
#define ll long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;

const int maxn = 1e5 + 7;
int n, m, k, res;
ll d[maxn];
bool vis[maxn];
vector<vector<ii>> adj;
priority_queue<pair<pair<ll, int>, bool>> q;

void dij(int s) {
	fill(d, d + maxn, 1e18);
	q.push({{0, s}, 0});
	d[s] = 0;

	while(q.size()){
		int v = q.top().fi.se;
		ll c = -q.top().fi.fi;
		bool flag = q.top().se;
		q.pop();

		if(d[v] <= c && flag) {
			++res;
			continue;
		} else if(d[v] > c && flag)
			d[v] = c;

		if(vis[v])
			continue;
		vis[v] = 1;

		for(int i = 0, u; i < (int)adj[v].size(); i++){
			u = adj[v][i].fi;
			if((ll)c + adj[v][i].se < d[u]) {
				d[u] = (ll)c + adj[v][i].se;
				q.push({{-d[u], u}, 0});
			}
		}
	}
}

int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0);

	std::freopen(task".inp", "r", stdin);
	std::freopen(task".out", "w", stdout);
	
	std::cin >> n >> m >> k;
	adj.resize(n);

	for(int i = 0; i < m; ++i) {
		int u, v, x;
		std::cin >> u >> v >> x;
		u--, v--;
		adj[u].push_back({v, x});
		adj[v].push_back({u, x});
	}

	for(int i = 0; i < k; ++i) {
		int s, y;
		std::cin >> s >> y;
		s--;
		q.push({{-y, s}, 1});
	}

	dij(0);

	std::cout << res;

	return 0;
}