#include <bits/stdc++.h>
#define task "LeHoi1"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert
#define sz size()

const int maxn = 1e5 + 7;
const int inf  = 1e9 + 7;

int n, m, k;
std::vector<int> adj[maxn];
std::vector<int> d(maxn, inf);
int p[maxn];
//int d[maxn];

void bfs(int s){
    std::queue<int> q;
    q.push(s);
    //memset(d, inf, sizeof d);
    d[s] = 0;

    while (q.size()){
        int t = q.front();
        q.pop();

        for (int v : adj[t])
            if (d[v] == inf){
                d[v] = d[t] + 1;
                q.push(v);
            }
    }
}

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    //std::freopen(task".inp", "r", stdin);
    //std::freopen(task".out", "w", stdout);

    std::cin >> n >> m >> k;
    for (int i = 1; i <= k; i++)
        std::cin >> p[i];
    while (m--){
        int u, v;
        std::cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    bfs(n);

    for (int i = 1; i <= k; i++)
        std::cout << d[p[i]] << " ";

    return 0;
}