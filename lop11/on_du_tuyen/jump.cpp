#include <bits/stdc++.h>
#define task "jump"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;

int n;
int a[maxn + 7], f[maxn + 7];

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
        f[i] = 0;
    }

    std::sort(a + 1, a + n + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i - 1; j >= 1; j--)
        {
            bool check = true;
            if (a[j] == a[i] - a[j])
            {
                if (a[j - 1] == a[i] - a[j] || a[j + 1] == a[i] - a[j])
                {
                    f[i] = std::max(f[i], f[j]);
                }
            }
            else if (std::binary_search(a + 1, a + n + 1, a[i] - a[j]))
            {
                f[i] = std::max(f[i], f[j]);
            }
        }
        f[i]++;
        ans = std::max(ans, f[i]);
    }

    /*for (int i = 1; i <= n; i++)
    {
        std::cout << f[i] << " ";
    }
    std::cout << "\n";
    for (int i = 1; i <= n; i++)
    {
        std::cout << f[i] << " ";
    }
    std::cout << "\n";*/

    std::cout << ans;

    return 0;
}
