#include <bits/stdc++.h>
#define task ""
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;

int n;
int a[maxn + 7], b[maxn + 7];
std::vector<int> adj[maxn + 7];
std::priority_queue<int, std::vector<int>> pq[maxn + 7];
int sum[maxn + 7];

void dfs(int u, int p)
{
    int heavy = -1;
    for (int v : adj[u])
    {
        if (v == p)
        {
            continue;
        }

        dfs(v, u);
        if (heavy == -1 || pq[v].size() > pq[heavy].size())
        {
            heavy = v;
        }
    }

    if (heavy != -1)
    {
        pq[u] = pq[heavy];
    }

    for (int v :adj[u])
    {
        if (v == p || v == heavy)
        {
            continue;
        }
    }
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
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        std::cin >> b[i];
    }

    for (int i = 1; i < n; i++)
    {
        int u, v;
        std::cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    return 0;
}
