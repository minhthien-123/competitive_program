#include <bits/stdc++.h>
#define task "sorting"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int inf  = 1e18;
const int maxn = 1e5 + 7;

int n, m;
bool vis[maxn];
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
    std::vector<int> a(n), f(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        f[i] = a[i];
    }

    std::sort(a.begin(), a.end());

    for (int i = 0; i < n; i++)
    {
        if (a[i] != f[i])
        {
            int tmp = -1;
            for (int j = i; j < n; j++)
            {
                if (f[j] == a[i])
                {
                    tmp = j;
                    break;
                }
            }

            if (tmp == -1)
            {
                std::cout << "No";
                return 0;
            }

            if ((f[i] + f[tmp]) > m)
            {
                std::cout << "No";
                return 0;
            }
        }
    }

    std::cout << "Yes";

    return 0;
}