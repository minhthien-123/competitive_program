#include <bits/stdc++.h>
#define task "k"
#define ll long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

const int maxn = 2e5 + 7;

int n, m, x, q = 0, ans = 0;
std::vector<int> adj[maxn];
bool vis[maxn];

void bfs(int u)
{
	std::queue<int> q;
	q.push(u);
	vis[u] = true;

	while (q.size())
	{
		int v = q.front();
		q.pop();
		for (auto e : adj[v])
			if (!vis[e])
			{
				q.push(e);
				vis[e] = true;
			}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	// std::freopen(task".inp", "r", stdin);
	// std::freopen(task".out", "w", stdout);

	std::cin >> n >> m >> x;

	while (m--)
	{
		int u, v, c;
		std::cin >> u >> v >> c;
		if (c >= x)
		{
			adj[u].pb(v);
			adj[v].pb(u);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			ans++;
			bfs(i);
			// for (int j = 1; j <= n; j++)
			// std::cout << vis[j] << " ";
			// std::cout << "\n";
		}
	}

	std::cout << ans;

	return 0;
}