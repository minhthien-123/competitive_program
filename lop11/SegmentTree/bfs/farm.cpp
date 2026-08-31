#include <bits/stdc++.h>
#define task "farm"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

const int maxn = 1e3 + 7;

int m, n, c, f, dc, df;
char a[maxn][maxn];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
bool vis[maxn][maxn];

bool check(int x, int y)
{
	if (a[x][y] == '#' || vis[x][y] || x < 1 || y < 1 || x > m || y > n)
		return false;
	return true;
}

void bfs(int u, int v)
{
	std::queue<ii> q;
	q.push({u, v});
	vis[u][v] = true;

	while (q.size())
	{
		ii t = q.front();
		q.pop();
		int x = t.fi, y = t.se;
		// std::cout << a[x][y] << "\n";
		if (a[x][y] == 'c')
			dc++;
		if (a[x][y] == 'f')
			df++;

		// std::cout << dc << " " << df << "\n";

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i], ny = y + dy[i];
			if (check(nx, ny))
			{
				vis[nx][ny] = true;
				q.push({nx, ny});
			}
		}
	}
}

signed main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	std::freopen(task ".inp", "r", stdin);
	std::freopen(task ".out", "w", stdout);

	std::cin >> m >> n;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			std::cin >> a[i][j];

	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			if (a[i][j] != '#' && !vis[i][j])
			{
				dc = 0, df = 0;
				bfs(i, j);

				// std::cout << dc << " " << df << "\n";

				if (dc > df)
					c += dc;
				else
					f += df;
			}

	std::cout << f << " " << c;

	return 0;
}