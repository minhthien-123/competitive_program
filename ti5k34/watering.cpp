#include <bits/stdc++.h>
#define task "watering"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5 + 7;

int n;
int a[maxn];

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

    int cnt = 0;

    a[0] = 0;
    int d = 1;
    for (int i = 1; i <= n; i++)






    
    {
        if (a[i - 1] <= a[i])
        {
            d++;
        }
        else
        {
            if (d > 1)
            {
                cnt++;
            }
            d = 1;
        }
    }

    //std::cout << kt << "\n";
    std::cout << cnt + (d > 1);

    return 0;
}

// 1 3 2 2