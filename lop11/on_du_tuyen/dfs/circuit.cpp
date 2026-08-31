#include <bits/stdc++.h>
#define ll long long
#define task "circuit"
#define pb push_back

const int maxn = 1e5 + 7;

std::vector<int> adj[maxn], parent(maxn, -1), ans;
std::vector<bool> vis(maxn, false), res(maxn, false);
int n, m;
std::map<std::pair<int, int>, int> d;

bool dfs(int u)
{
    vis[u] = true;
    res[u] = true;

    for (int v : adj[u])
    {
        if (!vis[v])
        {
            parent[v] = u;
            if (dfs(v))
                return true;
        }
        else if (res[v])
        {
            ans.pb(v);
            for (int x = u; x != v; x = parent[x])
                ans.pb(x);
            ans.pb(v);
            reverse(ans.begin(), ans.end());
            return true;
        }
    }

    res[u] = false;
    return false;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    //std::freopen(task ".inp", "r", stdin);
    //std::freopen(task ".out", "w", stdout);

    std::cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        std::cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
        d[{u, v}] = i;
        d[{v, u}] = i;
    }

    for (int i = 1; i <= n; i++)
        if (!vis[i] && dfs(i))
            break;

    if (!ans.empty())
    {
        std::cout << "YES\n";
        for (int i = 1; i < (int)ans.size(); i++)
            std::cout << d[{ans[i - 1], ans[i]}] << " ";
        // std::cout << ans[i] << " ";
    }
    else
        std::cout << "NO";

    return 0;
}
