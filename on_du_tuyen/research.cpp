#include <bits/stdc++.h>
#define task "research"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;

int n, m;
std::string s;
int d[maxn + 7], a[maxn + 7];
std::queue<int> q[3];
std::vector<int> adj[maxn + 7];

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> n >> m >> s;
    s = ' ' + s;
    for (int i = 1; i <= n; i++)
    {
        a[i] = s[i] - 'A';
    }

    while (m--)
    {
        int u, v;
        std::cin >> u >> v;
        d[v]++;
        adj[u].pb(v);
    }

    int sz = 0, tt = 0, ans = 0;

    for (int i = 1; i <= n; i++)
    {
        if (d[i] == 0)
        {
            if (a[i] == 1)
            {
                q[1].push(i);
            }
            else
            {
                q[0].push(i);
            }
        }
    }

    while (!q[0].empty() || !q[1].empty())
    {
        while (!q[tt].empty())
        {
            int u = q[tt].front();
            q[tt].pop();
            sz++;
            for (int v : adj[u])
            {
                d[v]--;
                if (d[v] == 0)
                {
                    if (a[v] == 1 - tt)
                    {
                        q[1 - tt].push(v);
                    }
                    else
                    {
                        q[tt].push(v);
                    }
                }
            }
        }
        tt = 1 - tt;
        ans++;
    }

    if (sz < n)
    {
        std::cout << -1;
    }
    else
    {
        std::cout << ans - 1;
    }

    return 0;
}
