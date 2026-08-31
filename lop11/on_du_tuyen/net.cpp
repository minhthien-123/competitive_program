#include <bits/stdc++.h>
#define task "net"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e3;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;

struct edge
{
    int x1, y1, x2, y2;
};

int m, n;
int par[maxn * maxn + 7], sz[maxn * maxn + 7];
std::vector<edge> edges;

void init(int v)
{
    par[v] = v;
    sz[v] = 1;
}

int acs(int v)
{
    if (v == par[v])
    {
        return v;
    }
    int p = acs(par[v]);
    par[v] = p;
    return p;
}

bool join(int a, int b)
{
    a = acs(a);
    b = acs(b);
    if (a == b)
    {
        return false;
    }
    if (sz[a] < sz[b])
    {
        std::swap(a, b);
    }
    par[b] = a;
    sz[a] += sz[b];
    return true;
}

int idx(int x, int y)
{
    return x * (n + 1) + y;
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

    std::cin >> m >> n;
    int x1, x2, y1, y2;
    while (std::cin >> x1 >> y1 >> x2 >> y2)
    {
        if (x1 > x2 || (x1 == x2 && y1 > y2))
        {
            std::swap(x1, x2);
            std::swap(y1, y2);
        }
        edges.pb({x1, y1, x2, y2});
    }

    for (int i = 0; i < (m + 1) * (n + 1); i++)
    {
        init(i);
    }

    for (auto e : edges)
    {
        int u = idx(e.x1, e.y1);
        int v = idx(e.x2, e.y2);
        join(u, v);
    }

    std::vector<edge> ans;
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            int u = idx(i, j);
            if (i < m)
            {
                if (join(u, idx(i + 1, j)))
                {
                    ans.pb({i, j, i + 1, j});
                }
            }
            if (j < n)
            {
                if (join(u, idx(i, j + 1)))
                {
                    ans.pb({i, j, i, j + 1});
                }
            }
        }
    }

    std::cout << ans.size() << "\n";
    for (auto e : ans)
    {
        std::cout << e.x1 << " " << e.y1 << " " << e.x2 << " " << e.y2 << "\n";
    }

    return 0;
}
