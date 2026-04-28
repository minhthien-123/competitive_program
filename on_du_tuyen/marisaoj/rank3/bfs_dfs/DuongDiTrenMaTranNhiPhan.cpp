#include <bits/stdc++.h>
#define task ""
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<int, ii>
#define fi first
#define se second
#define pb push_back

const int maxn = 1e3 + 7;
const int inf  = 1e8;

int dx[] = { 0, -1, 1, 0};
int dy[] = {-1,  0, 0, 1};
int n, m;
int a[maxn][maxn], d[maxn][maxn];
std::priority_queue<iii, std::vector<iii>, std::greater<iii>> pq;

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

		if (a[x][y] == 1) continue;

		for (int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (d[nx][ny] > d[x][y] + 1 && a[nx][ny] != 1){
				d[nx][ny] = d[x][y] + 1;
				pq.push({d[nx][ny], {nx, ny}});
			}
		}
	}
}

signed main(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0);

	//std::freopen(task".inp", "r", stdin);
	//std::freopen(task".out", "w", stdout);

	std::cin >> n >> m;
	for (int i = 1; i <= n; i++){
		std::string s;
		std::cin >> s;
		for (int j = 1; j <= m; j++)
			a[i][j] = s[j - 1] - '0';
	}

	pq.push({0, {1, 1}});
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			d[i][j] = inf;
	d[1][1] = 0;

	bfs();

	/*for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++)
			std::cout << d[i][j] * (d[i][j] != inf) << " ";
		std::cout << "\n";
	}*/

	std::cout << d[n][m];

	return 0;
}