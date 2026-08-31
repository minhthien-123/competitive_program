#include <bits/stdc++.h>
#define task "bfs3"
#define ll long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

const int maxn = 1e5 + 7;

int n, m, s, t;
std::vector<ii> adj[maxn];
std::vector<int> ans;
int par[maxn], pare[maxn];
bool vis[maxn];

void bfs(int s, int f)
{
    memset(par, -1, sizeof par);
    memset(vis, false, sizeof vis);
    memset(pare, -1, sizeof pare);

    std::queue<int> q;
    q.push(s);
    vis[s] = true;

    while (!q.empty())
    {
        int u = q.back();
        q.pop();

        if (u == f)
            return;

        for (auto v : adj[u])
        {
            if (!vis[v.fi])
            {
                par[v.fi] = u;
                pare[v.fi] = v.se;
                vis[v.fi] = true;
                q.push(v.fi);
            }
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    std::freopen(task ".inp", "r", stdin);
    std::freopen(task ".out", "w", stdout);

    std::cin >> n >> m >> s >> t;

    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        std::cin >> u >> v;
        adj[u].pb({v, i});
    }

    for (int i = 1; i <= n; i++)
        std::sort(adj[i].begin(), adj[i].end());

    bfs(s, t);

    for (int v = t; v != -1; v = par[v])
        ans.pb(pare[v]);

    std::reverse(ans.begin(), ans.end());

    for (int i = 1; i < ans.size(); i++)
        std::cout << ans[i] << " ";

    return 0;
}