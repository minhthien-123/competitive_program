#include <bits/stdc++.h>
#define task "mecung2"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

const int maxn = 1e3 + 7;
const int inf  = 1e18;

int m, n, q;
ii res;
int dx[] = {-1,  0, 1, 0};
int dy[] = { 0, -1, 0, 1};
bool a[maxn][maxn], vis[maxn][maxn];
int d[maxn][maxn];
int ans = LLONG_MAX;
std::priority_queue<std::pair<int, ii>, std::vector<std::pair<int, ii>>, std::greater<std::pair<int, ii>>> pq;

bool check(int x, int y){
	if (x < 1 || y < 1 || x > m || y > n) return false;
	return true;
}

void bfs(){
	while (pq.size()){
		int dist = pq.top().fi;
		ii t = pq.top().se;
		pq.pop();
		int x = t.fi, y = t.se;

		if (a[x][y] != 0) continue;

		if (dist > d[x][y]) continue;

		for (int i = 0; i < 4; i++){
			int nx = x + dx[i], ny = y + dy[i];
			if (check(nx, ny)){
				if (a[nx][ny] != 1 && d[nx][ny] > d[x][y] + 1) {
					d[nx][ny] = d[x][y] + 1;
					pq.push({d[nx][ny], {nx, ny}});
				}
			}
		}
	}
}

signed main(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0);

	std::freopen(task".inp", "r", stdin);
	std::freopen(task".out", "w", stdout);

	std::cin >> m >> n >> q;
	std::cin >> res.fi >> res.se;

	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			std::cin >> a[i][j];

	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			d[i][j] = inf;
	
	pq.push({0, res});
	d[res.fi][res.se] = 0;

	bfs();

	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			if (d[i][j] == inf)
				d[i][j] = -1;

	/*for (int i = 1; i <= m; i++){
		for (int j = 1; j <= n; j++)
			std::cout << d[i][j] << " ";
		std::cout << "\n";
	}*/

	while (q--){
		int u, v;
		std::cin >> u >> v;
		std::cout << d[u][v] << "\n";
	}

	return 0;
}
