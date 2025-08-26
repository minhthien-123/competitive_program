#include <bits/stdc++.h>
#define task "iparb"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e3;
const int inf  = 1e18;

int n;
int f[maxn + 7];

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

    f[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            f[j] += f[j - i];
        }
    }

    std::cout << f[n];

    return 0;
}
