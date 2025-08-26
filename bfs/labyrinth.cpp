#include <bits/stdc++.h>
#define task "labyrinth"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

const int maxn = 1e3 + 7;
const int inf  = 1e18;

int m, n;
ii res, resu;
int dx[] = {-1,  0, 1, 0};
int dy[] = { 0, -1, 0, 1};
bool a[maxn][maxn], vis[maxn][maxn];
int d[maxn][maxn];
int ans = LLONG_MAX;
char g[maxn][maxn];
ii par[maxn][maxn];
std::vector<ii> path;
std::queue<ii> q;
std::priority_queue<std::pair<int, ii>, std::vector<std::pair<int, ii>>, std::greater<std::pair<int, ii>>> pq;

bool check(int x, int y){
	if (x < 1 || y < 1 || x > m || y > n) return false;
	return true;
}

void bfs(ii s){
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
					par[nx][ny] = {x, y};
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

	std::cin >> m >> n;

	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++){
			std::cin >> g[i][j];
			par[i][j] = {-1, -1};
		}

	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			if (g[i][j] == '*'){
				res = {i, j};
				a[i][j] = 0;
			}else if (g[i][j] == '.'){
				a[i][j] = 0;
			}else{
				a[i][j] = 1;
			}


	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			d[i][j] = inf;
	
	pq.push({0, res});
	d[res.fi][res.se] = 1;

	/*std::cout << res.fi << " " << res.se << "\n";
	for (int i = 1; i <= m; i++){
		for (int j = 1; j <= n; j++)
			std::cout << a[i][j] << " ";
		std::cout << "\n";
	}*/

	bfs(res);

	/*for (int i = 1; i <= m; i++){
		for (int j = 1; j <= n; j++)
			std::cout << d[i][j] * (d[i][j] != inf) << " ";
		std::cout << "\n";
	}*/

	for (int i = 1; i <= m; i++){
		for (int j = 1; j <= n; j++)
			if ((i == 1 || j == 1 || i == m || j == n) && (d[i][j] != 0))
				ans = std::min(ans, d[i][j]);
	}

	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			if ((d[i][j] == ans) && (i == 1 || j == 1 || i == m || j == n)){
				resu = {i, j};
				//std::cout << i << " " << j << "\n";
				break;
			}

	//std::cout << resu.fi << " " << resu.se << "\n";

	//std::cout << par[res.fi][res.se].fi << " " << par[res.fi][res.se].se << "\n";

	for (ii t = resu; t.fi != -1 ; t = par[t.fi][t.se])
		path.pb(t);
	std::reverse(path.begin(), path.end());

	/*if (resu == res){
		std::cout << 1 << "\n" << res.fi << " " << res.se << "\n";
		return 0;
	}

	if (path.size() == 1){
		std::cout << 0;
		return 0;
	}*/

	for (int i = 1; i < (int)path.size(); i++){
		ii x = path[i - 1], y = path[i];
		if (x.fi == y.fi){
			if (x.se < y.se)
				std::cout << "E";
			else
				std::cout << "W";
		}else if (x.se == y.se){
			if (x.fi < y.fi)
				std::cout << "S";
			else
				std::cout << "N";
		}
	}

	return 0;
}
