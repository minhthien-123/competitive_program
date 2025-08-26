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
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

int n;
int a[maxn + 7];
std::vector<std::pair<int, int>> adj[maxn + 7];
int par[maxn + 7], sz[maxn + 7], pos[maxn + 7], arr[maxn + 7], d[maxn + 7];
int chainHead[maxn + 7], chainId[maxn + 7];
int curChain = 1, curPos = 1;
int st[4 * maxn + 7];

int eu[maxn + 7], ev[maxn + 7], ew[maxn + 7], edgePos[maxn + 7];

void dfs(int u, int p)
{
    sz[u] = 1;
    par[u] = p;
    for (auto ed : adj[u])
    {
        int v = ed.first;
        int id = ed.second;
        if (v == p)
            continue;
        par[v] = u;
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
    for (auto ed : adj[u])
    {
        int v = ed.first;
        if (v == p)
            continue;
        if (nxt == 0 || sz[v] > sz[nxt])
            nxt = v;
    }

    if (nxt)
    {
        hld(nxt, u);
    }

    for (auto ed : adj[u])
    {
        int v = ed.first;
        if (v == p || v == nxt)
            continue;
        curChain++;
        hld(v, u);
    }
}

int lca(int u, int v)
{
    while (chainId[u] != chainId[v])
    {
        if (d[chainHead[chainId[u]]] > d[chainHead[chainId[v]]])
        {
            u = par[chainHead[chainId[u]]];
        }
        else
        {
            v = par[chainHead[chainId[v]]];
        }
    }
    return (d[u] < d[v]) ? u : v;
}

void build(int id, int l, int r)
{
    if (l == r)
    {
        st[id] = a[arr[l]];
        return;
    }

    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    st[id] = std::max(st[id * 2], st[id * 2 + 1]);
}

void update(int id, int l, int r, int pos, int val)
{
    if (pos < l || pos > r)
    {
        return;
    }
    if (l == r && pos == l)
    {
        st[id] = val;
        return;
    }

    int mid = (l + r) / 2;
    update(id * 2, l, mid, pos, val);
    update(id * 2 + 1, mid + 1, r, pos, val);
    st[id] = std::max(st[id * 2], st[id * 2 + 1]);
}

int get(int id, int l, int r, int u, int v)
{
    if (v < l || r < u)
        return -inf;
    if (u <= l && r <= v)
        return st[id];
    int mid = (l + r) / 2;
    return std::max(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}

void update(int x, int val)
{
    update(1, 1, n, pos[x], val);
}

int get(int u, int v)
{
    int p = lca(u, v);
    int ans = -inf;
    while (chainId[u] != chainId[p])
    {
        ans = std::max(ans, get(1, 1, n, pos[chainHead[chainId[u]]], pos[u]));
        u = par[chainHead[chainId[u]]];
    }
    if (u != p)
    {
        ans = std::max(ans, get(1, 1, n, pos[p] + 1, pos[u]));
    }
    while (chainId[v] != chainId[p])
    {
        ans = std::max(ans, get(1, 1, n, pos[chainHead[chainId[v]]], pos[v]));
        v = par[chainHead[chainId[v]]];
    }
    if (v != p)
    {
        ans = std::max(ans, get(1, 1, n, pos[p] + 1, pos[v]));
    }
    return ans;
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    if (std::fopen(task ".inp", "r"))
    {
        std::freopen(task ".inp", "r", stdin);
        std::freopen(task ".out", "w", stdout);
    }

    int t;
    std::cin >> t;
    while (t--)
    {
        std::cin >> n;
        for (int i = 1; i <= n; i++)
        {
            adj[i].clear();
            par[i] = sz[i] = pos[i] = arr[i] = d[i] = chainHead[i] = chainId[i] = 0;
            a[i] = 0;
        }
        curChain = 1;
        curPos = 1;
        for (int i = 1; i <= n - 1; ++i)
        {
            int u, v, w;
            std::cin >> u >> v >> w;
            eu[i] = u;
            ev[i] = v;
            ew[i] = w;
            adj[u].pb({v, i});
            adj[v].pb({u, i});
        }

        d[1] = 0;
        dfs(1, 0);
        hld(1, 0);

        for (int i = 1; i < n; i++)
        {
            int u = eu[i], v = ev[i];
            int flag = (d[u] > d[v]) ? u : v;
            edgePos[i] = flag;
            a[flag] = ew[i];
        }
        a[1] = -inf;

        build(1, 1, n);

        std::string type;
        while (std::cin >> type)
        {
            if (type == "DONE")
                break;
            if (type == "QUERY")
            {
                int u, v;
                std::cin >> u >> v;
                std::cout << get(u, v) << "\n";
            }
            else if (type == "CHANGE")
            {
                int id, val;
                std::cin >> id >> val;
                int node = edgePos[id];
                update(node, val);
            }
        }
    }

    return 0;
}
