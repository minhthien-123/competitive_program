#include <bits/stdc++.h>
#define task ""
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5 + 7;

int n, timer = 0;
int a[2 * maxn], tin[maxn], tout[maxn], tour[2 * maxn], bit[2 * maxn];
std::vector<int> adj[maxn];

void dfs(int id, int u) {
    tour[++timer] = id;
    tin[id] = timer;

    for (int v : adj[id]) {
        if (v != u) {
            dfs(v, id);
        }
    }

    tour[++timer] = id;
    tout[id] = timer;
}

void update(int id, int val)
{
    for (id; id <= n; id += id & -id)
    {
        bit[id] += val;
    }
}

int get(int id)
{
    int sum = 0;
    for (id; id > 0; id -= id & -id)
    {
        sum += bit[id];
    }
    return sum;
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        std::cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }

    dfs(1, -1);

    /*for (int i = 1; i <= 2 * n; i++)
    {
        std::cout << tour[i] << " ";
    }
    std::cout << "\n";*/

    for (int i = 1; i < n; i++)
    {
        update(tin[a[i]], 1);
        update(tout[a[i]] + 1, -1);
        // for (int j = 1; j <= 2 * n; j++)
        // {
        //     std::cout << bit[j] << " ";
        // }
        // std::cout << "\n";
        std::cout << get(tin[a[i]]) << " " << get(tin[a[n]]) << "\n";
    }

    //std::cout << get(tin[a[n]]) << "\n";

    return 0;
}

// 2 7
// 5 6
// 1 10
// 3 4
// 8 9

// 1 4 5 5 2 2 4 3 3 1 2 7
// 0 0 0 0 0 0 0 0 0 0 0 0  // 0
// 0 1 1 1 1 1 1 1 0 0 0 0  // 1
// 0 1 1 1 2 2 1 1 0 0 0 0  // 1
// 1 2 2 2 3 3 2 2 1 1 0 0  //
// 1 2 3 3 3 3 2 2 1 1 0 0
// 1 2 3 3 3 3 2 3 2 1 0 0
