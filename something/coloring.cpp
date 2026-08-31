#include <bits/stdc++.h>
#define task "COLORING"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e6;
const int inf = 1e18;
const int mod = 1000000007;
const int inv = (mod + 1) / 2;

int dx[2] = {1, 0};
int dy[2] = {0, 1};

int m, n;
int a[maxn];
int par[maxn], sz[maxn], par2[maxn + 7], sz2[maxn + 7], r2[maxn + 7];
int csz[maxn];

void init(int i)
{
    par[i] = i;
    sz[i] = 0;
    csz[i] = 0;
}

int find(int v)
{
    if (v == par[v])
    {
        return v;
    }
    int p = find(par[v]);
    par[v] = p;
    return p;
}

void join(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        if (sz[a] < sz[b])
        {
            std::swap(a, b);
        }
        par[b] = a;
        sz[a] += sz[b];
    }
}

struct Edge
{
    int c1, c2, u, v;
};

bool cmp(Edge x, Edge y)
{
    return x.c1 == y.c1 ? x.c2 < y.c2 : x.c1 < y.c1;
}

int find2(int v)
{
    if (v == par2[v])
    {
        return v;
    }
    int p = find2(par2[v]);
    par2[v] = p;
    return p;
}

void join2(int a, int b)
{
    a = find2(a);
    b = find2(b);
    if (a != b)
    {
        if (sz2[a] < sz2[b])
        {
            std::swap(a, b);
        }
        par2[b] = a;
        sz2[a] += sz2[b];
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

    std::cin >> m >> n;
    for (int i = 0; i < m * n; i++)
    {
        std::cin >> a[i];
    }

    for (int i = 0; i < m * n; i++)
    {
        init(i);
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int u = i * n + j;
            for (int k = 0; k < 2; k++)
            {
                int nx = i + dx[k], ny = j + dy[k];
                if (nx < m && ny < n)
                {
                    int v = nx * n + ny;
                    if (a[u] == a[v])
                    {
                        join(u, v);
                    }
                }
            }
        }
    }

    for (int i = 0; i < m * n; i++)
    {
        csz[find(i)]++;
    }
    int best = 0;
    for (int i = 0; i < m * n; i++)
    {
        if (find(i) == i)
        {
            best = std::max(best, csz[i]);
        }
    }

    std::vector<Edge> e;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int u = i * n + j;
            for (int k = 0; k < 2; k++)
            {
                int ni = i + dx[k], nj = j + dy[k];
                if (ni < m && nj < n)
                {
                    int v = ni * n + nj;
                    if (a[u] != a[v])
                    {
                        int ru = find(u), rv = find(v);
                        if (ru != rv)
                        {
                            int c1 = a[u], c2 = a[v];
                            if (c1 > c2)
                            {
                                std::swap(c1, c2);
                                std::swap(ru, rv);
                            }
                            e.pb({c1, c2, ru, rv});
                        }
                    }
                }
            }
        }
    }

    std::sort(e.begin(), e.end(), cmp);

    std::vector<int> vec;
    int i = 0;
    while (i < e.size())
    {
        int j = i;
        int C1 = e[i].c1, C2 = e[i].c2;
        vec.clear();
        while (j < e.size() && e[j].c1 == C1 && e[j].c2 == C2)
        {
            vec.pb(e[j].u);
            vec.pb(e[j].v);
            j++;
        }
        std::sort(vec.begin(), vec.end());
        vec.erase(std::unique(vec.begin(), vec.end()), vec.end());

        for (int t = 0; t < vec.size(); t++)
        {
            par2[t] = t;
            sz2[t] = csz[vec[t]];
        }

        for (int t = i; t < j; t++)
        {
            int u = std::lower_bound(vec.begin(), vec.end(), e[t].u) - vec.begin();
            int v = std::lower_bound(vec.begin(), vec.end(), e[t].v) - vec.begin();
            join2(u, v);
            best = std::max(best, sz2[find2(u)]);
        }
        i = j;
    }

    std::cout << best;
    return 0;
}
