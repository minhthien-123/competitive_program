#include <bits/stdc++.h>
#define task "mstone"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

const int maxn = 400000;

int n, m;
bool used[maxn + 7];
int deg[maxn + 7];
std::vector<ii> adj[maxn + 7];

std::list<int> euler_walk(int u)
{
    std::vector<int> st;
    std::vector<int> edge;
    st.pb(u);
    edge.pb(-1);

    std::vector<int> path;

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
            st.pb(e.fi);
            edge.pb(e.se);
        }
        else
        {
            int tmp = edge.back();
            edge.pop_back();
            st.pop_back();
            if (tmp != -1)
            {
                path.pb((tmp + 1) / 2);
            }
        }
    }

    std::reverse(path.begin(), path.end());
    std::list<int> ans;
    for (int x : path)
    {
        ans.pb(x);
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

    std::cin >> n >> m;

    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        std::cin >> u >> v;
        int a = 2 * i - 1;
        int b = 2 * i;
        adj[u].pb({v, a});
        adj[v].pb({u, b});
        deg[u]++;
        deg[v]++;
    }

    if (deg[1] == 0)
    {
        std::cout << -1;
        return 0;
    }

    std::list<int> ans = euler_walk(1);

    if (ans.size() != 2 * m)
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
