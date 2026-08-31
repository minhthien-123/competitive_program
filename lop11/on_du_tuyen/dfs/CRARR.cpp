#include <bits/stdc++.h>
#define int long long
#define task "crarr"
#define pb push_back

const int maxn = 1e4 + 7;

std::vector<int> adj[maxn];
bool vis[maxn];
int d[maxn];
int k, n;
int ans = 0;

void dfs(int u) {
    vis[u] = true;
    d[u] = 1;
    for (int v : adj[u]) {
        if (!vis[v]) {
            dfs(v);
            d[u] += d[v];
        }
    }

    if (d[u] >= k){
        d[u] = 0;
        ans++;
    }
}

signed main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen(task".inp", "r", stdin);
    std::freopen(task".out", "w", stdout);

    std::cin >> k >> n;

    for (int i = 1; i < n; i++) {
        int x;
        std::cin >> x;
        adj[x].pb(i + 1);
    }

    std::memset(vis, false, sizeof vis);
    std::memset(d, -1, sizeof d);

    dfs(1);

    std::cout << ans;

    return 0;
}
