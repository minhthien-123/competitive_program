#include <bits/stdc++.h>
#define task "JzzhuandCities"
#define ll long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

const int maxn = 1e5 + 7;

int n, m, k, res;
int d[maxn];
bool vis[maxn];

std::vector<std::vector<ii>> adj;
std::priority_queue<std::pair<std::pair<ll, int>, bool>> q;

void dijk(int s) {
	memset(d, 1e18, sizeof d);
	q.push({{0, s}, 0});
	d[s] = 0;

	while(!q.empty()) {
		int v = q.top().fi.se;
		ll c = -q.top().fi.fi;
		bool flag = q.top().se;
		q.pop();

		if(d[v] <= c && flag) {
			res++;
			continue;
		} else if(d[v] > c && flag)
			d[v] = c;

		if(vis[v])
			continue;
		vis[v] = 1;

		for(int i = 0, u; i < adj[v].size(); ++i) {
			u = adj[v][i].fi;
			if(c + adj[v][i].se < d[u]){
				d[u] = c + adj[v][i].se;
				q.push({{-d[u], u}, 0});
			}
		}
	}
}


signed main(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0);

	std::freopen(task".inp", "r", stdin);
	std::freopen(task".out", "w", stdout);

	std::cin >> n >> m >> k;

	for (int i = 0; i < m; i++){
		int u, v, x;
		u--; v--;
		adj[u].pb({v, x});
		adj[v].pb({u, x});
	}

	return 0;

	for (int i = 0; i < k; i++){
		int s, y;
		std::cin >> s >> y;
		s--;
		q.push({{-y, s}, 1});
	}

	dijk(0);

	std::cout << res;

	return 0;
}