#include <bits/stdc++.h>
#define task "enet"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e3;
int num[maxn + 7], low[maxn + 7], timer;
int n, m, s, t;
std::vector<int> adj[maxn + 7];
std::stack<ii> st;
std::set<int> res;
bool vis[maxn + 7];

void dfs(int u)
{
    vis[u] = true;
    for (int v : adj[u])
    {
        if (!vis[v])
        {
            dfs(v);
        }
    }
}

void tarjan(int u, int p)
{
    num[u] = low[u] = ++timer;
    for (int v : adj[u])
    {
        if (v == p)
        {
            continue;
        }
        if (num[v])
        {
            low[u] = std::min(low[u], num[v]);
        }
        else
        {
            st.push({u, v});
            tarjan(v, u);
            low[u] = std::min(low[u], low[v]);
            if (low[v] >= num[u])
            {
                std::set<int> cur;
                while (st.top() != ii(u, v))
                {
                    cur.ins(st.top().se);
                    st.pop();
                }
                cur.ins(u);
                cur.ins(v);
                st.pop();
                if (cur.count(s) && cur.count(t))
                {
                    res = cur;
                }
            }
        }
    }
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

    std::cin >> n >> m >> s >> t;
    bool flag = false;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        std::cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
        if ((u == s && v == t) || (u == t && v == s))
        {
            flag = true;
        }
    }

    dfs(s);
    if (!vis[t])
    {
        std::cout << 0;
        return 0;
    }

    if (!flag)
    {
        adj[s].pb(t);
        adj[t].pb(s);
    }

    for (int u = 1; u <= n; u++)
    {
        if (!num[u])
        {
            tarjan(u, u);
        }
    }

    std::cout << res.size() << "\n";
    for (int u : res)
    {
        std::cout << u << "\n";
    }
    return 0;
}
