#include <bits/stdc++.h>
#define task "c"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<int, ii>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 2e5;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

int q, t, f[maxn + 7];
std::vector<int> top[maxn + 7];
std::vector<ii> a[maxn + 7];
std::vector<iii> adj[maxn + 7];

void dfs(int u, int p)
{
    for (iii e : adj[u])
    {
        if (e.fi == p)
        {
            continue;
        }
        std::vector<int> tmp = top[u];
        int h = e.se.fi;
        for (int p = 0; p < 11; p++)
        {
            if (h > tmp[p])
            {
                for (int t = 10; t > p; t--)
                {
                    tmp[t] = tmp[t - 1];
                }
                tmp[p] = h;
                break;
            }
        }
        top[e.fi] = tmp;
        f[e.fi] = f[u] + e.se.se;
        dfs(e.fi, u);
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

    std::cin >> t;
    for (int i = 2; i <= t; i++)
    {
        int b, h, v;
        std::cin >> b >> h >> v;
        adj[i].pb(iii(b, ii(h, v)));
        adj[b].pb(iii(i, ii(h, v)));
    }
    for (int i = 1; i <= t; i++)
    {
        top[i].resize(11);
    }

    dfs(1, -1);

    for (int i = 0; i <= 10; i++)
    {
        for (int j = 1; j <= t; j++)
        {
            a[i].pb(ii(top[j][i], f[j]));
        }
        std::sort(a[i].begin(), a[i].end());
        for (int j = 1; j < t; j++)
        {
            a[i][j].se = std::max(a[i][j].se, a[i][j - 1].se);
        }
    }

    std::cin >> q;
    while (q--)
    {
        int r, k;
        std::cin >> r >> k;
        int L = 0, R = a[k].size() - 1, ans = -1;
        while (L <= R)
        {
            int mid = (L + R) / 2;
            if (a[k][mid].fi <= r)
            {
                L = mid + 1;
                ans = mid;
            }
            else
            {
                R = mid - 1;
            }
        }

        std::cout << a[k][ans].se << "\n";
    }

    return 0;
}
