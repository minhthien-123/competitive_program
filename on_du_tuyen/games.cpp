#include <bits/stdc++.h>
#define task "games"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

const int maxn = 1e3 + 7;
const int inf  = 1e9 + 7;

std::vector<ii> adj[maxn];
std::vector<int> S, A, B;
int n, m, s, t, a, b;

std::vector<int> dij(int l){
    std::vector<int> d(n + 7, inf);

    std::priority_queue<ii, std::vector<ii>, std::greater<ii>> pq;

    d[l] = 0;
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
                pq.push({d[v], v});
            }
        }
    }

    return d;
}

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen(task".inp", "r", stdin);
    std::freopen(task".out", "w", stdout);

    std::cin >> n >> m;
    std::cin >> s >> t >> a >> b;

    for (int i = 1; i <= m; i++){
        int u, v, z;
        std::cin >> u >> v >> z;
        adj[u].pb({v, z});
        adj[v].pb({u, z});
    }

    S = dij(s);
    A = dij(a);
    B = dij(b);

    //std::cout << S[a] << ' ' <<    S[b] << " " << A[t] << " " << B[t] << "\n";

    if ((S[a] == inf && S[b] == inf) || (S[a] == inf && A[t] == inf) || (S[b] == inf && B[t] == inf) || (A[t] == inf && B[t] == inf))
        std::cout << -1;
    else
        std::cout << std::min(S[a] + B[t], S[b] + A[t]);

    return 0;
}
