#include <bits/stdc++.h>
#define task ""
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 2e5;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;

int n, q;
int a[maxn + 7];
std::vector<int> adj[maxn + 7];
int par[maxn + 7], d[maxn + 7], pos[maxn + 7], arr[maxn + 7], sz[maxn + 7];
int chainHead[maxn + 7], chainId[maxn + 7];
int curPos = 1, curChain = 1;
int st[4 * maxn + 7];

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
    for (int v : adj[u])
    {
        if (v == p)
        {
            continue;
        }
        if (nxt == 0 || sz[v] > sz[nxt])
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
        curChain++;
        hld(v, u);
    }
}

int lca(int u, int v)
{
    while (chainId[u] != chainId[v])
    {
        if (chainId[u] > chainId[v])
        {
            u = par[chainHead[chainId[u]]];
        }
        else
        {
            v = par[chainHead[chainId[v]]];
        }
    }

    if (d[u] < d[v])
    {
        return u;
    }
    else
    {
        return v;
    }
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
    st[id] = st[id * 2] + st[id * 2 + 1];
}

void update(int id, int l, int r, int pos, int val)
{
    if (pos < l || pos > r)
    {
        return;
    }
    if (l == r && l == pos)
    {
        st[id] = val;
        return;
    }

    int mid = (l + r) / 2;
    update(id * 2, l, mid, pos, val);
    update(id * 2 + 1, mid + 1, r, pos, val);
    st[id] = st[id * 2] + st[id * 2 + 1];
}

int get(int id, int l, int r, int u, int v)
{
    if (v < l || r < u)
    {
        return 0;
    }
    if (u <= l && r <= v)
    {
        return st[id];
    }

    int mid = (l + r) / 2;
    return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
}

void update(int x, int val)
{
    update(1, 1, n, pos[x], val);
}

int get(int u, int v)
{
    int p = lca(u, v);
    int ans = 0;
    while (chainId[u] != chainId[p])
    {
        ans += get(1, 1, n, pos[chainHead[chainId[u]]], pos[u]);
        u = par[chainHead[chainId[u]]];
    }
    while (chainId[v] != chainId[p])
    {
        ans += get(1, 1, n, pos[chainHead[chainId[v]]], pos[v]);
        v = par[chainHead[chainId[v]]];
    }

    if (d[u] < d[v])
    {
        ans += get(1, 1, n, pos[u], pos[v]);
    }
    else
    {
        ans += get(1, 1, n, pos[v], pos[u]);
    }

    return ans;
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

    std::cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }

    for (int i = 1; i < n; i++)
    {
        int u, v;
        std::cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(1, -1);
    hld(1, -1);
    build(1, 1, n);

    while (q--)
    {
        int type, u, v;
        std::cin >> type;
        if (type == 1)
        {
            std::cin >> u >> v;
            update(u, v);
        }
        else
        {
            std::cin >> v;
            std::cout << get(1, v) << "\n";
        }
    }

    return 0;
}
