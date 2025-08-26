#include <bits/stdc++.h>
#define task "mecung0"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

const int maxn = 1e3 + 7;

int m, n, q, x, y;
int dx[] = { 0, -1, 1, 0};
int dy[] = {-1,  0, 0, 1};
int a[maxn][maxn];
bool vis[maxn][maxn];
bool ans[maxn][maxn];
ii res;

bool check(int x, int y){
	if (vis[x][y] || x < 1 || y < 1 || x > m || y > n) return false;
	return true;
}

void bfs(ii s){
	std::queue<ii> q;
	q.push(s);
	vis[s.fi][s.se] = ans[s.fi][s.se] = true;
	//std::cout << s.fi << " " << s.se << " " << check(s.fi, s.se) << "\n";

	while (q.size()){
		ii t = q.front();
		q.pop();

		if (a[t.fi][t.se] != 0) continue;

		for (int i = 0; i < 4; i++){
			int nx = t.fi + dx[i], ny = t.se + dy[i];
			if (check(nx, ny)){
				//std::cout << nx << " " << ny << "\n";
				q.push({nx, ny});
				vis[nx][ny] = true;
				if (a[nx][ny] == 0) ans[nx][ny] = true;
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

	bfs(res);

	/*for (int i = 1; i <= m; i++){
		for (int j = 1; j <= n; j++)
			std::cout << ans[i][j] << " ";
		std::cout << "\n";
	}*/

	while (q--){
		int u, v;
		std::cin >> u >> v;
		//std::cout << d[u][v] << "\n";
		std::cout << ans[u][v] << "\n";
	}

	return 0;
}

//1 0 0 1 0 1 1
//1 0 1 0 0 1 0
//1 0 0 0 1 0 1
//0 0 1 0 A A A 
//1 1 0 1 A 1 A
//1 1 0 1 1 A A