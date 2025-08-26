#include <bits/stdc++.h>
#define task "net2line"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 5005;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

struct Edge
{
    int u, v, w, idx;
};

int t;
int n;
int U[maxn + 7], V[maxn + 7], W[maxn + 7];
int par[maxn + 7], sz[maxn + 7];
int par1[maxn + 7], sz1[maxn + 7];
bool flag[maxn * 3 + 7];

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

bool cmp(Edge u, Edge v)
{
    if (u.w != v.w)
    {
        return u.w < v.w;
    }
    return u.idx < v.idx;
}

void init1(int v)
{
    par1[v] = v;
    sz1[v] = 1;
}

int acs1(int v)
{
    if (v == par1[v])
    {
        return v;
    }
    int p = acs1(par1[v]);
    par1[v] = p;
    return p;
}

bool join1(int a, int b)
{
    a = acs1(a);
    b = acs1(b);
    if (a == b)
    {
        return false;
    }
    if (sz1[a] < sz1[b])
    {
        std::swap(a, b);
    }
    par1[b] = a;
    sz1[a] += sz1[b];
    return true;
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

    std::cin >> t;
    while (t--)
    {
        std::cin >> n;

        int mx = 3 * n + 5;
        for (int i = 0; i < mx; i++)
        {
            flag[i] = false;
        }

        for (int i = 1; i <= 2 * n; i++)
        {
            init(i);
            init1(i);
        }
        for (int i = 1; i < n; i++)
        {
            std::cin >> U[i];
        }
        for (int i = 1; i < n; i++)
        {
            std::cin >> V[i];
        }
        for (int i = 1; i <= n; i++)
        {
            std::cin >> W[i];
        }
        std::vector<Edge> edges;
        int idx = 0;
        for (int i = 1; i <= n - 1; i++)
        {
            edges.pb({i, i + 1, U[i], idx++});
        }
        for (int i = 1; i <= n - 1; i++)
        {
            edges.pb({n + i, n + i + 1, V[i], idx++});
        }
        for (int i = 1; i <= n; i++)
        {
            edges.pb({i, i + n, W[i], idx++});
        }
        std::sort(edges.begin(), edges.end(), cmp);

        int ans = 0;
        int cnt = 0;
        for (auto &e : edges)
        {
            if (join(e.u, e.v))
            {
                ans += e.w;
                cnt++;
                flag[e.idx] = true;
                if (cnt == 2 * n - 1)
                {
                    break;
                }
            }
        }

        if (cnt != 2 * n - 1)
        {
            std::cout << "-1\n";
        }
        else
        {
            if (ans % 2 == 0)
            {
                std::cout << ans << "\n";
            }
            else
            {
                int res = inf;
                for (int i = 0; i < idx; i++)
                {
                    if (!flag[i])
                    {
                        continue;
                    }
                    int ans1 = 0;
                    int cnt1 = 0;

                    for (int v = 1; v <= 2 * n; v++)
                    {
                        init1(v);
                    }

                    for (auto &e : edges)
                    {
                        if (e.idx == i)
                        {
                            continue;
                        }
                        if (join1(e.u, e.v))
                        {
                            ans1 += e.w;
                            cnt1++;
                            if (cnt1 == 2 * n - 1)
                            {
                                break;
                            }
                        }
                    }

                    if (cnt1 != 2 * n - 1)
                    {
                        continue;
                    }
                    if (ans1 % 2 == 0)
                    {
                        res = std::min(ans1, res);
                    }
                }

                if (res == inf)
                {
                    std::cout << "-1\n";
                }
                else
                {
                    std::cout << res << "\n";
                }
            }
        }
    }

    return 0;
}
