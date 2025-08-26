#include <bits/stdc++.h>
#define task "dsu"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5 + 7;
int par[maxn], sz[maxn], sum[maxn];
int n, q;

void init(){
    for (int i = 1; i <= n; i++){
        par[i] = i;
        sz[i] = 1;
        sum[i] = i;
    }
}

int find_set(int v){
    if (v == par[v]) return v;
    int p = find_set(par[v]);
    par[v] = p;
    return p;
}

void union_sets(int a, int b){
    a = find_set(a);
    b = find_set(b);

    if (a != b){
        if (sz[a] < sz[b]) std::swap(a, b);
        par[b] = a;
        sz[a] += sz[b];
        sum[a] += sum[b];
        sum[b] = 0;
    }
}

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen(task".inp", "r", stdin);
    std::freopen(task".out", "w", stdout);

    std::cin >> n >> q;

    init();

    while (q--){
        int t;
        std::cin >> t;
        if (t == 1){
            int u, v;
            std::cin >> u >> v;
            union_sets(u, v);
        }else{
            int u;
            std::cin >> u;
            std::cout << sum[find_set(u)] << "\n";
        }
    }

    return 0;
}

