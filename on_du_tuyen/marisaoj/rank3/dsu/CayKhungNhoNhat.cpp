#include <bits/stdc++.h>
#define task ""
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<std::pair<int, int>, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5 + 7;

int n, m, ans = 0;
std::vector<iii> adj;
int sz[maxn], par[maxn];


void make_set()
{
    for (int v = 0; v <= n; v++)
    {
        par[v] = v;
    }
}

int find_set(int v)
{
    if (v == par[v])
    {
        return v;
    }
    int p = find_set(par[v]);
    par[v] = p;
    return p;
}

bool join(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a == b)
    {
        return false;
    }
    par[b] = a;
    return true;
}

bool cmp(iii a, iii b)
{
    return a.se < b.se;
}

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> n >> m;

    while (m--){
        int u, v, c;
        std::cin >> u >> v >> c;
        adj.pb({{u, v}, c});
    }

    make_set();

    std::sort(adj.begin(), adj.end(), cmp);

    for (auto e : adj)
    {
        if (!join(e.fi.fi, e.fi.se))
        {
            continue;
        }

        ans += e.se;
    }

    std::cout << ans;

    return 0;
}
