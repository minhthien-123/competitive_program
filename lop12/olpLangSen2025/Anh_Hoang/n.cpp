#include <bits/stdc++.h>
#define task "n"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 3e6;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;

int n;
int a[maxn + 7];
int d[maxn + 7];

void bfs(int u)
{
    for (int i = 1; i <= n; i++)
    {
        d[i] = inf;
    }
    d[u] = 0;
    std::queue<int> q;
    q.push(u);
    int pos = 0;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int i = std::max(v + 1, pos); i <= std::min(v + a[v], n); i++)
        {
            if (d[i] > d[v] + 1)
            {
                d[i] = d[v] + 1;
                q.push(i);
            }
        }
        pos = std::max(pos, v + a[v]);
        if (pos == n)
        {
            break;
        }
    }
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

    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }

    bfs(1);
    if (d[n] != inf)
    {
        std::cout << d[n];
    }
    else
    {
        std::cout << -1;
    }

    return 0;
}
