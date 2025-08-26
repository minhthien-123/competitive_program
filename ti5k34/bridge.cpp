#include <bits/stdc++.h>
#define task "bridge"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int inf = 1e18;

int x, y, a, b, m;

bool check(int mid)
{
    int tmpx = x, tmpa = a;
    for (int i = 1; i <= m; i++)
    {
        int tmp2 = inf, tmp1 = inf;
        for (int j = 0; j <= tmpx; j++)
        {
            int tmp = mid - y * j;
            if (tmp <= 0)
            {
                if (y * j < tmp1 * y + tmp2 * b)
                {
                    tmp1 = j;
                    tmp2 = 0;
                }
                break;
            }
            int cur = ceil(1.0 * tmp / b);

            if (cur > tmpa)
            {
                continue;
            }
            if (cur * b + y * j < tmp1 * y + tmp2 * b)
            {
                tmp1 = j;
                tmp2 = cur;
            }
        }

        tmpx -= tmp1;
        tmpa -= tmp2;
        if (tmpx < 0 || tmpa < 0)
        {
            return false;
        }
    }
    return true;
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

    std::cin >> x >> y >> a >> b >> m;

    int l=1,r=inf,ans;
    while (l<=r)
    {
        int mid=(l+r)/2;
        if (check(mid))
        {
            ans=mid;
            l=mid+1;
        }
        else
            r=mid-1;
    }
    std::cout<<ans;

    return 0;
}
