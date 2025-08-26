#include <bits/stdc++.h>
#define task "viplist"
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

int n, m, k;
std::vector<int> adj[maxn + 7];
int deg[maxn + 7];
bool flag[maxn + 7];
std::deque<int> dq;

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

    std::cin >> n >> m >> k;
    while (m--)
    {
        int u, v;
        std::cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
        deg[u]++;
        deg[v]++;
    }


    for (int i = 1; i <= n; i++)
    {
        if (deg[i] < k)
        {
            flag[i] = true;
            dq.pb(i);
        }
    }

    while (dq.size())
    {
        int u = dq.front();
        dq.pop_front();
        for (int v : adj[u])
        {
            if (!flag[v])
            {
                deg[v]--;
                if (deg[v] < k)
                {
                    flag[v] = true;
                    dq.pb(v);
                }
            }
        }
    }

    std::vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        if (!flag[i])
        {
            ans.pb(i);
        }
    }

    std::cout << ans.size() << "\n";
    for (int i : ans)
    {
        std::cout << i << " ";
    }

    return 0;
}
