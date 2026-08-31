#include <bits/stdc++.h>
#define task "SPERFECT"
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

int q;
int n, m;
int num[maxn + 7], low[maxn + 7], timer;
int comp[maxn + 7], cnt;
int topo[maxn + 7], nTopo;
bool inStack[maxn + 7], vis[maxn + 7];
std::stack<int> st;
std::vector<int> adj[maxn + 7], g[maxn + 7];
std::vector<int> dag[maxn + 7];
std::set<int> vec;

void tarjan(int u)
{
    num[u] = low[u] = ++timer;
    st.push(u);
    inStack[u] = true;
    for (int v : adj[u])
    {
        if (!num[v])
        {
            tarjan(v);
            low[u] = std::min(low[u], low[v]);
        }
        else if (inStack[v])
        {
            low[u] = std::min(low[u], num[v]);
        }
    }
    if (low[u] == num[u])
    {
        cnt++;
        int v;
        do
        {
            v = st.top();
            st.pop();
            inStack[v] = false;
            comp[v] = cnt;
            g[cnt].pb(v);
        } while (v != u);
    }
}

void dfs(int u)
{
    vis[u] = true;
    for (int v : dag[u])
    {
        if (!vis[v])
        {
            dfs(v);
        }
    }
    topo[++nTopo] = u;
}

bool solve()
{
    std::set<int> cs;
    for (int x : vec)
        cs.ins(comp[x]);
    for (int c : cs)
        dag[c].clear();
    for (int u : vec)
    {
        int cu = comp[u];
        for (int v : adj[u])
        {
            int cv = comp[v];
            if (cu != cv && cs.count(cv))
            {
                dag[cu].pb(cv);
            }
        }
    }
    for (int c : cs)
    {
        auto &out = dag[c];
        if (out.size() > 1)
        {
            std::sort(out.begin(), out.end());
            out.erase(std::unique(out.begin(), out.end()), out.end());
        }
    }
    for (int c : cs)
    {
        vis[c] = false;
    }
    nTopo = 0;
    for (int c : cs)
    {
        if (!vis[c])
        {
            dfs(c);
        }
    }
    if (nTopo <= 1)
    {
        return true;
    }
    std::reverse(topo + 1, topo + nTopo + 1);
    for (int i = 1; i < nTopo; i++)
    {
        int u = topo[i], v = topo[i + 1];
        if (!std::binary_search(dag[u].begin(), dag[u].end(), v))
        {
            return false;
        }
    }
    return true;
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

    std::cin >> q;
    while (q--)
    {
        std::cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            adj[i].clear();
            g[i].clear();
            num[i] = low[i] = comp[i] = 0;
            inStack[i] = false;
            topo[i] = 0;
        }
        while (!st.empty())
        {
            st.pop();
        }
        timer = cnt = nTopo = 0;
        vec.clear();

        for (int i = 1, u, v; i <= m; i++)
        {
            std::cin >> u >> v;
            adj[u].pb(v);
            vec.ins(u);
            vec.ins(v);
        }

        for (int u = 1; u <= n; u++)
        {
            if (!num[u])
            {
                tarjan(u);
            }
        }

        if (solve())
        {
            std::cout << "YES";
        }
        else
        {
            std::cout << "NO";
        }
        std::cout << "\n";
    }
    return 0;
}
