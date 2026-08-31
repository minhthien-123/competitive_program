#include <bits/stdc++.h>
#define task "triangles"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;
const int inf  = 1e18;

int n, d1, d2, ans, x;
int a[maxn + 7], b[maxn + 7];
std::map<int, int> m;

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
    for (int i = 1, x; i <= n; i++)
    {
        std::cin >> x;
        m[x]++;
        if (m[x] == 1)
        {
            a[d1] = x;
            d1++;
        }
        if (m[x] == 2)
        {
            b[d2] = x;
            d2++;
        }
    }

    std::sort(a, a + d1);
    for (int i = 1; i < d1 - 1; i++)
    {
        for (int j = i + 1; j < d1; j++)
        {
            x = std::lower_bound(a + j + 1, a + d1, a[i] + a[j]) - a;
            ans += x - j - 1;
        }
    }

    for (int i = 0; i < d2; i++)
    {
        
    }

    return 0;
}
