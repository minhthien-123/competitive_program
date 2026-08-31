#include <bits/stdc++.h>
#define task "yg"
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
int cntX[maxn + 7], cntY[maxn + 7];
int p = 0, q = 0;

void make_set(int v)
{
    par[v] = v;
    sz[v] = 1;
    cntX[v] = (v <= k);
    cntY[v] = (v > k);
}

int find_set(int v)
{
    if (v == par[v])
    {
        return v;
    }
    return par[v] = find_set(par[v]);
}

void union_sets(int a, int b, int i)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        if (sz[a] < sz[b])
        {
            std::swap(a, b);
        }
        par[b] = a;
        sz[a] += sz[b];
        cntX[a] += cntX[b];
        cntY[a] += cntY[b];
        if (cntX[a] == k && p == 0)
        {
            p = i;
        }
        if (cntY[a] == (n - k) && q == 0)
        {
            q = i;
        }
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

    std::cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        make_set(i);

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        std::cin >> u >> v;
        union_sets(u, v, i);
    }

    std::cout << p << " " << q << "\n";
    return 0;
}
