#include <bits/stdc++.h>
#define task "sumxor"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e6;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;

int n;
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

    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }

    int ans = 0;
    for (int i = 0; i < 20; i++)
    {
        int cnt0 = 0, cnt1 = 0;
        for (int j = 1; j <= n; j++)
        {
            if (a[j] % 2 == 0)
            {
                cnt0++;
            }
            else
            {
                cnt1++;
            }
            a[j] /= 2;
        }

        int tmp = cnt0 * cnt1 * (1 << i);
        ans += tmp;
    }

    std::cout << ans;

    return 0;
}
// 7 1 1 1
// 3 0 1 1
// 5 1 0 1