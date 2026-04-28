#include <bits/stdc++.h>
#define task ""
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

int m, n;
ii a[maxn + 7];
int c[maxn + 7];

int dis(ii x, ii y)
{
    return abs(x.fi - y.fi) + abs(x.se - y.se);
}

bool check(int k)
{
    memset(c, 0, sizeof c);
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (c[i])
        {
            continue;
        }
        cnt++;
        
        c[i] = cnt;
        for (int j = 1; j <= n; j++)
        {
            if (dis(a[i], a[j]) >= k)
            {
                c[j] = cnt;
            }
        }
    }

    return cnt <= m;
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

    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i].fi >> a[i].se;
    }

    int l = 1, r = 2e6;
    int ans;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (check(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    check(ans);
    for (int i = 1; i <= n; i++)
    {
        std::cout << c[i] << " ";
    }


    return 0;
}
