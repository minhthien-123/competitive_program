#include <bits/stdc++.h>
#define task "circle"
#define ll long long
#define pb push_back
#define ii std::pair<int, int>
#define fi first
#define se second

const int maxn = 1e6 + 7;

int n;
int pos[maxn], a[maxn], b[maxn], next[maxn];
std::vector<int> adj[maxn], vec, ans[maxn];
bool vis[maxn];
std::vector<ii> res;

void dfs(int u){
    if (vis[u]) return;
    vec.pb(u);
    vis[u] = true;

    for (int v : adj[u])
        if (!vis[v])
            dfs(v);
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen(task".inp", "r", stdin);
    std::freopen(task".out", "w", stdout);

    std::cin >> n;
    for (int i = 1; i <= n; i++){
        std::cin >> a[i];
        pos[a[i]] = i;
        b[i] = a[i];
        adj[i].pb(a[i]);
    }

    int m = 0;
    for (int i = 1; i <= n; i++){
        vec.clear();
        dfs(i);
        if (vec.size()) m++;
        for (int j : vec){
            ans[m].pb(j);
        }
        //if (vec.size()) std::cout << "\n";
    }

    if (m == 1){
        std::cout << 0;
        return 0;
    }

    std::cout << m << "\n";

    for (int i = 1; i < m; i++)
        next[ans[i][ans[i].size() - 1]] = ans[i + 1][0];
        
    next[ans[m][ans[m].size() - 1]] = ans[1][0];

    for (int i = 1; i <= n; i++)
        if (next[i] != 0)
            std::cout << i << " " << next[i] << "\n";

    return 0;
}