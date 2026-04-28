#include <bits/stdc++.h>
#define task "picture"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

const int maxn = 1e3 + 7;

int m, n, ans = 0;
bool vis[maxn][maxn];
int a[maxn][maxn];
const int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
const int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};

bool check(int x, int y)
{
	if (vis[x][y] || x < 1 || y < 1 || x > m || y > n)
		return false;
	return true;
}

void bfs(int u, int v)
{
	int val = a[u][v];
	std::queue<ii> q;
	q.push({u, v});
	vis[u][v] = true;

	while (q.size())
	{
		ii t = q.front();
		q.pop();
		int x = t.fi;
		int y = t.se;

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (check(nx, ny) && a[nx][ny] == val)
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
	std::cin.tie(0); std::cout.tie(0);

	//std::freopen(task ".inp", "r", stdin);
	//std::freopen(task ".out", "w", stdout);

	std::cin >> m >> n;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			std::cin >> a[i][j];
		}
	}

	for (int x = 1; x <= m; x++)
	{
		for (int y = 1; y <= n; y++)
		{

			if (!vis[x][y])
			{
				int tmp = a[x][y];
				bool flag = true;

				for (int i = 0; i < 8; i++)
				{
					int nx = x + dx[i];
					int ny = y + dy[i];

					if (check(nx, ny) && a[nx][ny] > tmp)
					{
						flag = false;
						break;
					}
				}

				if (flag)
				{
					ans++;
					bfs(x, y);
				}
			}
		}
	}

	std::cout << ans;

	return 0;
}