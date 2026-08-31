#include <bits/stdc++.h>
#define task "snum"
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

int n, m, C;
std::vector<int> adj[maxn + 7];
int num[maxn + 7], low[maxn + 7], timer;
int comp[maxn + 7], cnt;
bool inStack[maxn + 7];
std::stack<int> st;
int d[maxn + 7], rep[maxn + 7];
bool flag[maxn + 7];
std::vector<ii> res;

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
        ++cnt;
        int v;
        do
        {
            v = st.top();
            st.pop();
            inStack[v] = false;
            comp[v] = cnt;
            rep[cnt] = v;
        } while (v != u);
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

    std::cin >> n >> m >> C;
    while (m--)
    {
        int u, v;
        std::cin >> u >> v;
        adj[u].pb(v);
    }

    for (int u = 1; u <= n; u++)
    {
        if (!num[u])
        {
            tarjan(u);
        }
    }

    int t = comp[C];
    flag[t] = true;

    for (int u = 1; u <= n; u++)
        for (int v : adj[u])
        {
            int cu = comp[u];
            int cv = comp[v];
            if (cu != cv)
            {
                d[cu]++;
            }
        }

    for (int i = 1; i <= cnt; i++)
    {
        if (d[i] == 0 && i != t)
        {
            res.pb({rep[i], C});
        }
    }

    std::cout << res.size() << "\n";
    for (auto e : res)
    {
        std::cout << e.fi << " " << e.se << "\n";
    }

    return 0;
}
