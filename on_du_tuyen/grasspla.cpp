#include <bits/stdc++.h>
#define task "grasspla"
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
std::vector<int> adj[maxn + 7];
int par[maxn + 7], pos[maxn + 7], arr[maxn + 7], d[maxn + 7], sz[maxn + 7];
int chainHead[maxn + 7], chainId[maxn + 7];
int curChain = 1, curPos = 1;

void dfs(int u, int p)
{
    sz[u] = 1;
    par[u] = p;
    for (int v : adj[u])
    {
        if (v == p)
        {
            continue;
        }
        d[v] = d[u] + 1;
        dfs(v, u);
        sz[u] += sz[v];
    }
}

void hld(int u, int p)
{
    if (!chainHead[curChain])
    {
        chainHead[curChain] = u;
    }

    chainId[u] = curChain;
    pos[u] = curPos;
    arr[curPos] = u;
    curPos++;

    int nxt = 0;
    for (int v : adj[u])
    {
        if (v == p)
        {
            continue;
        }
        if (!nxt || sz[v] > sz[nxt])
        {
            nxt = v;
        }
    }

    if (nxt)
    {
        hld(nxt, u);
    }

    for (int v : adj[u])
    {
        if (v == p || v == nxt)
        {
            continue;
        }
        hld(v, u);
    }
}

int lca(int u, int v)
{
    while (chainId[u] != chainId[v])
    {
        if (chainId[u] > chainId[v])
        {

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
    for (int i = 1; i < n; i++)
    {
        int u, v;
        std::cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    return 0;
}
