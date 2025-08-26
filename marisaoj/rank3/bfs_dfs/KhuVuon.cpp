#include <bits/stdc++.h>
#define task ""
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

const int maxn = 1e3 + 7;
const int inf  = 1e9;

int dx[] = { 0, -1, 1, 0};
int dy[] = {-1,  0, 0, 1};
int n, m;
int a[maxn][maxn];
int ans = 0;
std::vector<int> resu;

bool check(int x, int y){
	if (x < 1 || y < 1 || x > n || y > m) return false;
	return true;
}

int bfs(int u, int v){
	std::queue<ii> q;
	q.push({u, v});

	int res = 0;
	if (a[u][v] == 2) res = 1;
	a[u][v] = 1;

	while (q.size()){
		ii t = q.front();
		q.pop();
		int x = t.fi;
		int y = t.se;

		for (int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (check(nx, ny) && a[nx][ny] != 1){
				if (a[nx][ny] == 2)
					res++;
				a[nx][ny] = 1;
				q.push({nx, ny});
			}
		}
	}

	return res;
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
		for (int j = 1; j <= m; j++){
			if (s[j - 1] == '.')
				a[i][j] = 0;
			if (s[j - 1] == '#')
				a[i][j] = 1;
			if (s[j - 1] == 'x')
				a[i][j] = 2;
		}
	}

	/*for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++)
			std::cout << a[i][j] << " ";
		std::cout << "\n";
	}*/

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (a[i][j] != 1){
				//std::cout << i << " " << j << "\n";
				int tmp = bfs(i, j);
				if (tmp != 0)
					resu.pb(tmp);
			}

	/*std::cout << bfs(1, 1);
	std::cout << "\n";
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++)
			std::cout << a[i][j] << " ";
		std::cout << "\n";
	}*/

	std::sort(resu.begin(), resu.end());

	for (int i : resu)
		std::cout << i << " ";

	return 0;
}