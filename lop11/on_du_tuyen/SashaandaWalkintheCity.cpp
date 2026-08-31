#include <bits/stdc++.h>
#define task "SashaandaWalkintheCity"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

const int maxn = 3e5 + 7;
const int mod  = 998244353;

int t;
std::vector<int> adj[maxn];
int f[maxn], g[maxn];

void dfs(int u,int val){
    int prod = 1, sum = 0;
    bool flag = false;
    for(int v : adj[u]){
        if(v == val)continue;
        flag = true;
        dfs(v, u);
        prod = prod * f[v] % mod;
        sum = (sum + f[v] + g[v] - 1) % mod;
    }
    if(flag) {
        f[u] = prod + 1;
        g[u] = sum % mod;
    }else {
        f[u] = 2;
        g[u] = 0;
    }
}
signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    //std::freopen(task".inp", "r", stdin);
    //std::freopen(task".out", "w", stdout);

    std::cin >> t;
    while (t--){
        int n;
        std::cin >> n;
        for(int i = 1; i <= n; i++) 
            adj[i].clear();
        for(int i = 1; i < n; i++){
            int u,v;
            std::cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }

        dfs(1,0);

        std::cout << (f[1] + g[1]) % mod << "\n";
    }

    return 0;
}