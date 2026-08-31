#include <bits/stdc++.h>
#define task "dsu"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5 + 7;

int sz[maxn], par[maxn];
int n, q;

void make_set(){
    for (int v = 0; v <= n; v++){
        par[v] = v;
        sz[v] = 1;
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
    }
}

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    //std::freopen(task".inp", "r", stdin);
    //std::freopen(task".out", "w", stdout);

    std::cin >> n >> q;

    make_set();

    while (q--){
        int t, u, v;
        std::cin >> t >> u >> v;
        if (t == 1){
            union_sets(u, v);
        }else{
            if (find_set(u) == find_set(v)){
                std::cout << "YES\n";
            }else{
                std::cout << "NO\n";
            }
        }
    }

    return 0;
}

