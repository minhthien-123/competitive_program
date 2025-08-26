#include <bits/stdc++.h>
#define task "bfs_1"
#define ll long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

const int maxn = 1e3 + 7;

int n, m;
std::vector<int> adj[maxn], ans;
int par[maxn];
bool vis[maxn];

void bfs(int s)
{
	memset(par, -1, sizeof par);
	memset(vis, false, sizeof vis);

	std::queue<int> q;
	q.push(s);
	vis[s] = true;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int v : adj[u])
		{
			if (!vis[v])
			{
				par[v] = u;
				vis[v] = true;
				q.push(v);
			}
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

	std::cin >> n >> m;
	while (m--)
	{
		int u, v;
		std::cin >> u >> v;
		adj[u].pb(v);
	}

	bfs(1);
	for (int v = n; v != -1; v = par[v])
		ans.pb(v);
	std::reverse(ans.begin(), ans.end());
	for (int i : ans)
		std::cout << i << " ";

	return 0;
}