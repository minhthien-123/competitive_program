#include <bits/stdc++.h>
#define task "numtrans"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 100;
const int tt = 100000;
const int mx = 3 * tt + 7;

int n, t;
int a[maxn + 7];
bool vis[mx];
int par[mx];
int trace[mx];
std::queue<int> q;

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

    std::cin >> n >> t;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }

    vis[tt] = true;
    q.push(0);

    bool found = (t == 0);
    while (!q.empty() && !found)
    {
        int u = q.front();
        q.pop();
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == 0)
                continue;
            int v = u + a[i];
            int idx = v + tt;
            if (idx < 0 || idx >= mx)
                continue;
            if (!vis[idx])
            {
                vis[idx] = true;
                par[idx] = u;
                trace[idx] = a[i];
                if (v == t)
                {
                    found = true;
                    break;
                }
                q.push(v);
            }
        }
    }

    if (!vis[t + tt])
    {
        std::cout << -1;
        return 0;
    }

    std::vector<int> ans;
    int cur = t;
    while (cur != 0)
    {
        int idx = cur + tt;
        ans.pb(trace[idx]);
        cur = par[idx];
    }
    std::reverse(ans.begin(), ans.end());

    for (int x : ans)
    {
        std::cout << x << " ";
    }
    return 0;
}
