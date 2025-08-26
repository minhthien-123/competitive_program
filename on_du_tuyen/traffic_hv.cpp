#include <bits/stdc++.h>
#define task "traffic"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

const int maxn = 1e5;
const int inf = 1e18;

struct Edge
{
    int to;
    int x, y, c;
};

int n, q;
std::vector<Edge> adj[maxn + 7];
std::vector<int> vec;

int get_cost(int s, int t, int need)
{
    std::vector<int> parent(n + 1, -1);
    std::vector<Edge> pedge(n + 1);
    std::queue<int> qu;
    qu.push(s);
    parent[s] = s;

    while (!qu.empty())
    {
        int u = qu.front();
        qu.pop();
        if (u == t)
            break;
        for (auto &e : adj[u])
        {
            if (parent[e.to] == -1)
            {
                parent[e.to] = u;
                pedge[e.to] = e;
                qu.push(e.to);
            }
        }
    }

    int total = 0;
    int cur = t;
    while (cur != s)
    {
        auto e = pedge[cur];
        if (e.x >= need)
        {
            // free
        }
        else if (e.y >= need)
        {
            total += e.c;
        }
        else
        {
            return inf;
        }
        cur = parent[cur];
    }
    return total;
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v, x, y, c;
        std::cin >> u >> v >> x >> y >> c;
        adj[u].pb({v, x, y, c});
        adj[v].pb({u, x, y, c});
        vec.pb(x);
        vec.pb(y);
    }

    std::sort(vec.begin(), vec.end());
    vec.erase(std::unique(vec.begin(), vec.end()), vec.end());

    std::cin >> q;
    while (q--)
    {
        int s, t, money;
        std::cin >> s >> t >> money;
        int l = 0, r = vec.size() - 1;
        int ans = -1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            int cost = get_cost(s, t, vec[mid]);
            if (cost <= money)
            {
                ans = vec[mid];
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        std::cout << ans << "\n";
    }
}
