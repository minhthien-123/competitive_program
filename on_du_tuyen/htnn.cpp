#include <bits/stdc++.h>
#define task "htnn"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

const int maxn = 5e3 + 7;

std::vector<ii> adj[maxn];
int n, m;
ii res;

ii dij(int l){
    std::vector<int> d(n + 7, LLONG_MAX);
    std::vector<int> c(n + 7, 0);

    std::priority_queue<ii, std::vector<ii>, std::greater<ii>> pq;

    d[l] = 0;
    c[l] = 1;
    pq.push({0, l});

    while (!pq.empty()){
        int s = pq.top().fi;
        int u = pq.top().se;
        pq.pop();

        if (s != d[u])
            continue;

        for (ii e : adj[u]){
            int v = e.fi;
            int w = e.se;

            if (s + w < d[v]){
                d[v] = s + w;
                c[v] = c[u];
                pq.push({d[v], v});
            }else if (s + w == d[v])
                c[v] += c[u];
        }
    }

    return {d[n], c[n]};
}

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen(task".inp", "r", stdin);
    std::freopen(task".out", "w", stdout);

    std::cin >> n >> m;

    for (int i = 1; i <= m; i++){
        int k, u, v, l;
        std::cin >> k >> u >> v >> l;

        if (k == 1)
            adj[u].pb({v, l});
        else{
            adj[u].pb({v, l});
            adj[v].pb({u, l});
        }
    }

    res = dij(1);
    std::cout << res.fi << " " << res.se;

    return 0;
}
