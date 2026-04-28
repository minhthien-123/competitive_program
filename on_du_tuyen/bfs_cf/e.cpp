#include <bits/stdc++.h>
#define task
#define ll long long

const int maxn = 2e5 + 9;
int n, m, s, ans = 0;
int par[maxn], d[maxn];
bool vis[maxn];
std::vector<int> adj[maxn];

void bfs(int u){
    std::fill_n(d, n + 9, -1);
    std::fill_n(vis, n + 9, false);

    std::queue<int> q;
    q.push(u);
    d[u] = 0;
    vis[u] = true;
    while (!q.empty()){
        int v = q.front();
        q.pop();
        for (auto e : adj[v]){
            if (!vis[e]){
                vis[e] = true;
                d[e]   = d[v] + 1;
                q.push(e);
            }
        }
    }
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    //std::freopen(task".inp", "r", stdin);
    //std::freopen(task".out", "w", stdout);

    std::cin >> n >> m >> s;
    while (m--){
        int u, v;
        std::cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs(s);
    for (int i = 1; i <= n; i++)
        if (d[i] != -1)
            ans++;

    std::cout << ans;

    return 0;
}
