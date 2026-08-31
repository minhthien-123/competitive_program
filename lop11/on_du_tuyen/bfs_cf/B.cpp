#include <bits/stdc++.h>
#define task
#define int long long

std::set<int> adj[200007];
int n, m;

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    //std::freopen(task".inp", "r", stdin);
    //std::freopen(task".out", "w", stdout);

    std::cin >> n >> m;
    while(m--){
        int u, v;
        std::cin >> u >> v;

        adj[u].insert(v);
        adj[v].insert(u);
    }

    for (int i = 1; i <= n; i++){
        std::cout << adj[i].size() << " ";
        for (auto j : adj[i])
            std::cout << j << " ";
        std::cout << "\n";
    }

    return 0;
}
