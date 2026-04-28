#include <bits/stdc++.h>
#define task "DoXe"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5 + 7;

int n;
int a[maxn], d[maxn];

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
        int x;
        std::cin >> x;
        if (d[x] == 0)
        {
            a[i] = x;
        }
        else
        {
            int j = i;
            while (d[x] != 0)
            {
                x++;
                if (x == (n + 1))
                {
                    x = 1;
                }
            }
            a[j] = x;
        }
        d[x] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        std::cout << a[i] << " ";
    }

    return 0;
}
