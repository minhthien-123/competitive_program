#include <bits/stdc++.h>
#define task "DistinctColors"
#define ll long long

const int maxn = 2e5 + 7;

int n, a[maxn], parent[maxn], sz[maxn], color[maxn];
std::vector<int> adj[maxn];

void make_set(int v){
    color[v] = 1;
    parent[v] = v;
    sz[v] = 1;
}

int find_set(int v){
    if (v == parent[v]) return v;
    int p = find_set(parent[v]);
    parent[v] = p;
    return p;
}

void union_sets(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if (a != b){
        if (sz[a] < sz[b]) std::swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        color[a] += color[b];
    }
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen(task".inp", "r", stdin);
    std::freopen(task".out", "w", stdout);

    std::cin >> n;
    for (int i = 1; i <= n; i++){
        std::cin >> a[i];
        make_set(i);
    }

    for (int i = 1; i < n; i++){
        int a, b;
        std::cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);

        union_sets(a, b);
    }

    for (int i = 1; i <= n; i++)
        std::cout << color[i] << " ";

    return 0;
}
