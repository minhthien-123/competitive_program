#include <bits/stdc++.h>
#define task "sovung"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

const int maxn = 1e3 + 7;
int n, m, k;
bool a[maxn][maxn];
int dx[] = {-1,  0, 1, 0};
int dy[] = { 0, -1, 0, 1};
int ans = 0;

bool check(int x, int y){
	if (x < 1 || y < 1 || x > m || y > n) return false;
	return true;
}

void bfs(int u, int v){
	std::queue<ii> q;
	a[u][v] = true;
	q.push({u, v});

	while (q.size()){
		ii t = q.front();
		q.pop();
		int x = t.fi, y = t.se;

		for (int i = 0; i < 4; i++){
			int nx = x + dx[i], ny = y + dy[i];
			if (check(nx, ny) && !a[nx][ny]){
				a[nx][ny] = true;
				q.push({nx, ny});
			}
		}
	}
}

signed main(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0);

	std::freopen(task".inp", "r", stdin);
	std::freopen(task".out", "w", stdout);

	std::cin >> m >> n >> k;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			a[i][j] = 0;

	while(k--){
		int x, y, z, t, l, r;
		std::cin >> x >> y >> z >> t;
		if (x == z)
			for (int i = std::min(y, t); i <= std::max(y, t); i++)
				a[x][i] = 1;
		else
			for (int i = std::min(x, z); i <= std::max(x, z); i++)
				a[i][y] = 1;
	}
	

	/*for (int i = 1; i <= m; i++){
		for (int j = 1; j <= n; j++)
			std::cout << a[i][j] << " ";
		std::cout << "\n";
	}*/

	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			if (!a[i][j]){
				ans++;
				bfs(i, j);
			}

	std::cout << ans;

	return 0;
}
// 0 0 0 0 1 0 0 0 0 0
// 1 1 1 1 1 1 1 1 1 1
// 0 0 0 0 1 0 0 0 0 0
// 0 0 0 0 1 0 0 0 0 0
// 1 1 1 1 1 1 0 0 0 0
// 0 0 0 0 1 0 0 0 0 0
// 0 0 0 0 1 0 0 0 0 0
// 0 0 0 0 1 0 0 0 0 0
// 0 0 0 0 1 0 0 0 0 0