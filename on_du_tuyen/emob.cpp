#include <bits/stdc++.h>
#define task "emob"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e4;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;

#define maxe 150111
#define rep(i, n) for (int i = 0; i < n; i++)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)

struct HopcroftKarp
{
    int nx, ny, E, adj[maxe], next[maxe], last[maxn],
        matx[maxn], maty[maxn], que[maxn], level[maxn], run[maxn];

    void init(int _nx, int _ny)
    {
        nx = _nx;
        ny = _ny;
        E = 0;
        FOR(i, 1, nx)
        matx[i] = -1,
        last[i] = -1;
        FOR(i, 1, ny)
        maty[i] = -1;
    }

    void add(int x, int y)
    {
        adj[E] = y;
        next[E] = last[x];
        last[x] = E++;
    }

    bool bfs()
    {
        bool found = false;
        int size = 0;
        FOR(x, 1, nx)
        {
            if (matx[x] != -1)
                level[x] = -1;
            else
            {
                level[x] = 0;
                que[size++] = x;
            }
        }
        rep(i, size)
        {
            for (int x = que[i], e = last[x]; e != -1; e = next[e])
            {
                int y = adj[e];
                if (maty[y] == -1)
                    found = true;
                else if (level[maty[y]] == -1)
                {
                    level[maty[y]] = level[x] + 1;
                    que[size++] = maty[y];
                }
            }
        }

        return found;
    }

    int dfs(int x)
    {
        for (int &e = run[x]; e != -1; e = next[e])
        {
            int y = adj[e];
            if (maty[y] == -1 || (level[maty[y]] == level[x] + 1 && dfs(maty[y])))
            {
                maty[y] = x;
                matx[x] = y;
                return 1;
            }
        }
        return 0;
    }

    int maxMatching()
    {
        int total = 0;
        while (bfs())
        {
            FOR(x, 1, nx)
            run[x] = last[x];
            FOR(x, 1, nx)
            if (matx[x] == -1) total += dfs(x);
        }
        return total;
    }

} hopkarp;

int n, m, k;
int h[maxn + 7], p[maxn + 7], t[maxn + 7];

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> n >> m >> k;
    for (int i = 1; i <= k; i++)
    {
        std::cin >> h[i];
    }
    for (int i = 1; i <= k; i++)
    {
        std::cin >> p[i];
    }
    for (int i = 1; i <= k; i++)
    {
        std::cin >> t[i];
    }

    return 0;
}
