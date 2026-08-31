#include <bits/stdc++.h>
#define task "euler"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

const int maxn = 4e5;

int n, m;
bool used[maxn + 7];
int deg[maxn + 7];
std::vector<ii> adj[maxn + 7];

std::list<int> euler_walk(int u)
{
    std::vector<int> st;
    std::vector<int> path;
    st.push_back(u);
    while (!st.empty())
    {
        int v = st.back();
        while (!adj[v].empty() && used[adj[v].back().se])
        {
            adj[v].pop_back();
        }
        if (!adj[v].empty())
        {
            auto e = adj[v].back();
            adj[v].pop_back();
            used[e.se] = 1;
            st.push_back(e.fi);
        }
        else
        {
            path.push_back(v);
            st.pop_back();
        }
    }
    std::list<int> ans;
    for (auto it = path.rbegin(); it != path.rend(); ++it)
    {
        ans.pb(*it);
    }
    return ans;
}

bool check()
{
    for (int i = 1; i <= n; i++)
    {
        if (deg[i] % 2)
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

    std::cin >> n >> m;

    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        std::cin >> u >> v;
        adj[u].pb({v, i});
        adj[v].pb({u, i});
        deg[u]++;
        deg[v]++;
    }

    if (!check() || deg[1] == 0)
    {
        std::cout << -1;
        return 0;
    }

    std::list<int> ans = euler_walk(1);

    if (ans.size() != m + 1)
    {
        std::cout << -1;
        return 0;
    }

    for (auto x : ans)
    {
        std::cout << x << " ";
    }
    return 0;
}
