#include <bits/stdc++.h>
#define task "bfs2"
#define ll long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

const int maxn = 1e5 + 7;

int n, m, s, t;
std::vector<int> adj[maxn], ans;
int par[maxn];
bool vis[maxn];

void bfs(int s, int f) {
    memset(par, -1, sizeof par);
    memset(vis, false, sizeof vis);

    std::queue <int> q;
    q.push(s);
    vis[s] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (u == f) return;

        for (int v : adj[u]) {
            if (!vis[v]) {
                par[v] = u;
                vis[v] = true;
                q.push(v);
            }
        }
    }
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen(task".inp", "r", stdin);
	std::freopen(task".out", "w", stdout);

    std::cin >> n >> m >> s >> t;

    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        adj[u].pb(v);
    }

    for (int i = 0; i <= n; i++)
        std::sort(adj[i].begin(), adj[i].end());

    bfs(s, t);

    for (int v = t; v != -1; v = par[v])
        ans.pb(v);
    
    std::reverse(ans.begin(), ans.end());
    
    for (int i : ans)
        std::cout << i << " ";

    return 0;
}