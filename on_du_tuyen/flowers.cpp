#include <bits/stdc++.h>
#define task "FLOWERS"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 2e4;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

int n, u, v;
std::vector<int> adj[maxn + 7];
int num[maxn + 7], low[maxn + 7], timer;
int comp[maxn + 7];
bool inStack[maxn + 7], flag[maxn + 7];
std::vector<int> res;
std::stack<int> st;
std::vector<std::vector<int>> ans;

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
        std::vector<int> cur;
        int v;
        do
        {
            v = st.top();
            st.pop();
            inStack[v] = false;
            cur.pb(v);
        } while (u != v);
        ans.pb(cur);
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

    std::cin >> n;
    while (std::cin >> u >> v)
    {
        adj[u].pb(v);
    }

    for (int u = 1; u <= n; u++)
    {
        if (!num[u])
        {
            tarjan(u);
        }
    }

    std::memset(comp, -1, sizeof(comp));

    for (int i = 0; i < ans.size(); i++)
    {
        for (int x : ans[i])
        {
            comp[x] = i;
        }
    }

    std::memset(flag, 0, sizeof(flag));
    for (int u = 1; u <= n; u++)
    {
        for (int v : adj[u])
        {
            if (comp[u] != comp[v])
            {
                flag[comp[u]] = true;
            }
        }
    }

    int mx = inf;
    for (int i = 0; i < ans.size(); i++)
    {
        int sz = ans[i].size();
        if (!flag[i] && sz > 0 && sz < mx)
        {
            mx = sz;
            res = ans[i];
        }
    }

    std::sort(res.begin(), res.end());

    std::cout << res.size() << "\n";
    for (int x : res)
    {
        std::cout << x << " ";
    }
    std::cout << "\n";

    return 0;
}
