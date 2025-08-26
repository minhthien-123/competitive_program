#include <bits/stdc++.h>
#define task "mecung4"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<int, ii>
#define fi first
#define se second
#define pb push_back

const int maxn = 1e3 + 7;
const int inf = 1e9;

int m, n;
int dx[] = { 0, -1, 1, 0};
int dy[] = {-1,  0, 0, 1};
int a[maxn][maxn], d[maxn][maxn];
int vis[maxn][maxn];
std::priority_queue<iii, std::vector<iii>, std::greater<iii>> pq;
std::deque<ii> dq;

bool check(int x, int y){
	if (x < 1 || y < 1 || x > m || y > n) return false;
	return true;
}

int bfs(){
	//std::deque<iii> dq;

	while (dq.size()){
		ii t = dq.front();
		dq.pop_front();
		int x = t.fi;
		int y = t.se;

		if (vis[x][y]) continue;
		vis[x][y] = 1;

		for (int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			int tmp = (a[nx][ny] != a[x][y]);
			if (check(nx, ny) && d[nx][ny] > d[x][y] + tmp){
				d[nx][ny] = d[x][y] + tmp;
				if (tmp == 0) dq.push_front({nx, ny});
				else		  dq.push_back({nx, ny});
			}
		}
	}

	int ans = inf;

	/*for (int i = 1; i <= m; i++){
		for (int j = 1; j <= n; j++)
			std::cout << d[i][j] << " ";
		std::cout << "\n";
	}*/

	for (int i = 1; i <= m; i++)
		ans = std::min(ans, d[i][n]);
	return ans;
}

signed main(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0);

	std::freopen(task".inp", "r", stdin);
	std::freopen(task".out", "w", stdout);

	std::cin >> m >> n;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			std::cin >> a[i][j];

	int res = inf;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			d[i][j] = inf;
	for (int i = 1; i <= m; i++){
		//std::cout << bfs(i, 1) << "\n";
		d[i][1] = 1;
		pq.push({0, {i, 1}});
		dq.push_front({i, 1});
		//vis[i][1] = 1;
		/*for (int i = 1; i <= m; i++){
			for (int j = 1; j <= n; j++)
				std::cout << d[i][j] << " ";
			std::cout << "\n";
		}
		std::cout << "\n";*/
	}

	std::cout << bfs();
	/*std::cout << "\n";
	for (int i = 1; i <= m; i++){
			for (int j = 1; j <= n; j++)
				std::cout << d[i][j] << " ";
			std::cout << "\n";
		}
	std::cout << "\n";*/

	//std::cout << bfs(1, 1);
	//std::cout << res;

	return 0;
}