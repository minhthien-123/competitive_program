#include <bits/stdc++.h>
#define task "labyrinth"
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
int par[maxn + 7], sz[maxn + 7];
std::vector<int> adj[maxn + 7];
bool flag[maxn + 7];
std::vector<char> res;

void init(int v)
{
    par[v] = v;
    sz[v] = 1;
}

int find(int u)
{
    if (par[u] == u)
    {
        return u;
    }
    return par[u] = find(par[u]);
}

void join(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        par[b] = a;
    }
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    std::freopen(task ".inp", "r", stdin);
    std::freopen(task ".out", "w", stdout);

    std::cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        init(i);
    }

    while (m--)
    {
        int u, v;
        std::cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    while (k--)
    {
        char type;
        std::cin >> type;
        if (type == 'X')
        {
            int u;
            std::cin >> u;
            flag[u] = true;
            for (int v : adj[u])
            {
                if (flag[v])
                {
                    join(u, v);
                }
            }
        }
        else
        {
            int s, t;
            std::cin >> s >> t;
            if (find(s) == find(t))
            {
                res.pb('Y');
            }
            else
            {
                res.pb('N');
            }
        }
    }

    for (char c : res)
    {
        std::cout << c;
    }

    return 0;
}
