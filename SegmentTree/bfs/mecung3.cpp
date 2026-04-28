#include <bits/stdc++.h>
#define task "mecung3"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<int, ii>
#define fi first
#define se second
#define pb push_back

const int maxn = 1e3 + 7;
const int inf = 1e9;

int m, n, q;
ii res;
std::priority_queue<iii, std::vector<iii>, std::greater<iii>> pq;
int dx[] = { 0, -1, 1, 0};
int dy[] = {-1,  0, 0, 1};
int d[maxn][maxn], a[maxn][maxn];

bool check(int x, int y){
	if (x < 1 || y < 1 || x > m || y > n) return false;
	return true;
}

void bfs(){
	while (pq.size()){
		int dist = pq.top().fi;
		ii t = pq.top().se;
		pq.pop();
		int x = t.fi;
		int y = t.se;

		if (dist > d[x][y]) continue;

		for (int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (check(nx, ny)){
				int tmp = (a[nx][ny] != a[x][y]);
				if (d[nx][ny] > d[x][y] + tmp){
					d[nx][ny] = d[x][y] + tmp;
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

	/*for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			if (a[i][j] == inf)
				a[i][j] = -1;*/

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