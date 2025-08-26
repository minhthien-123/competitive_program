#include <bits/stdc++.h>
#define task "mindis"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;
const int inf  = 1e18;

int n, q;
int a[maxn + 7];

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }

    std::sort(a + 1, a + n + 1);
    a[0] = inf;
    a[n + 1] = inf;
    /*for (int i = 1; i <= n; i++)
    {
        std::cout << a[i] << " ";
    }
    std::cout << "\n";*/

    while (q--)
    {
        int x;
        std::cin >> x;
        int tmp = std::lower_bound(a, a + n, x) - a;
        if (tmp == 0)
        {
            tmp = 1;
        }
        if (tmp == n + 1)
        {
            tmp = n;
        }
        //std::cout << tmp << " ";
        std::cout << std::min(abs(x - a[tmp - 1]), abs(x - a[tmp])) << "\n";
    }

    return 0;
}

