#include <bits/stdc++.h>
#define task "SAFENET0"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 3e4;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;

int n, m;
std::vector<int> adj[maxn + 7];
int low[maxn + 7], num[maxn + 7], timer;
std::stack<ii> s;
std::set<int> ans;

void tarjan(int u, int p)
{
    num[u] = low[u] = ++timer;

    for (int v : adj[u])
    {
        if (v == p)
        {
            continue;
        }

        if (!num[v])
        {
            s.push({u, v});
            tarjan(v, u);

            low[u] = std::min(low[u], low[v]);
            if (low[v] >= num[u])
            {
                std::set<int> res;
                ii e;
                do
                {
                    e = s.top();
                    s.pop();
                    res.ins(e.fi);
                    res.ins(e.se);
                } while (e != ii(u, v));
                if (res.size() > ans.size())
                {
                    ans = res;
                }
            }
        }
        else
        {
            low[u] = std::min(low[u], num[v]);
        }
    }
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

    std::cin >> n >> m;

    if (m == 0)
    {
        std::cout << "1\n1";
        return 0;
    }

    while (m--)
    {
        int u, v;
        std::cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!num[i])
        {
            tarjan(i, i);
        }
    }

    std::cout << ans.size() << "\n";
    for (int i : ans)
    {
        std::cout << i << " ";
    }

    return 0;
}
