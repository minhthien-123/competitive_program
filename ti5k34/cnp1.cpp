#include <bits/stdc++.h>
#define task "cnp1"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e6 + 7;

int n, m;
int a[maxn];

bool check(int x)
{
    int s = 0;
    int d = 0;
    for (int i = 1; i <= n; i++)
    {
        s += a[i];
        if (s > x){
            if (a[i] > x)
            {
                return false;
            }
            else
            {
                s = a[i];
                d++;
            }
        }
    }

    if (s > 0)
    {
        d++;
    }

    //std::cout << x << " " << d << "\n";
    return d <= m;
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
        std::cin >> a[i];
    }

    int l = 1, r = 1e9;
    int ans = LLONG_MAX;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (check(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    std::cout << ans;

    return 0;
}