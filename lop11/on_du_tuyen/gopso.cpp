#include <bits/stdc++.h>
#define task "gopso"
#define int long long
#define pb push_back

const int maxn = 2e6 + 7;

int n, q;
int par[maxn], d[maxn], par_help[maxn], sz[maxn];
bool vis[maxn];

void make_set(int v) {
    par[v] = v;
    par_help[v] = v;
    sz[v] = 1;
}

int find_set(int v) {
    if (v == par[v]) return v;
    int p = find_set(par[v]);
    par[v] = p;
    return p;
}

int find_set_help(int v) {
    if (v == par_help[v]) return v;
    int p = find_set_help(par_help[v]);
    par_help[v] = p;
    return p;
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b]) std::swap(a, b);
        par[b] = a;
        sz[a] += sz[b];
    }
}

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen(task".inp", "r", stdin);
    std::freopen(task".out", "w", stdout);

    std::cin >> n >> q;

    for (int i = 0; i <= n; i++)
        make_set(i);

    while (q--){
        int type, l, r;
        std::cin >> type >> l >> r;
        l--; r--;
        if (type == 1)
            union_sets(l, r);
        else if (type == 2){
            while (true){
                l = find_set_help(l);
                if (l < r){
                    union_sets(l, l + 1);
                    par_help[l] = l + 1;
                }else
                    break;
            }
        }else{
            l = find_set(l);
            r = find_set(r);
            if (l == r)
                std::cout << "YES\n";
            else
                std::cout << "NO\n";
        }
    }

    return 0;
}
