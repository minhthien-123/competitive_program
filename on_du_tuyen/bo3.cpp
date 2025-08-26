#include <bits/stdc++.h>
#define task "bo3"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

int n;
int a[maxn + 7];
int l[maxn + 7], r[maxn + 7];

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    if (std::fopen(task ".inp", "r"))
    {
        std::freopen(task ".inp", "r", stdin);
        std::freopen(task ".out", "w", stdout);
    }

    std::cin >> n;
    int mx = 0;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        r[a[i]]++;
        mx = std::max(mx, a[i]);
    }

    int ans = 0;
    if (r[0] >= 3)
    {
        ans = -2 * r[0] * (r[0] - 1) * (r[0] - 2) / 6;
    }


    for (int k = 1; k <= n; k++)
    {
        int x = a[k];
        r[x]--;

        for (int i = 0; i <= x; i++)
        {
            int j = x - i;
            ans += l[i] * r[j];
        }

        for (int j = 0; j <= mx; j++)
        {
            int i = x + j;
            if (i <= mx)
            {
                ans += l[i] * r[j];
            }
        }

        for (int i = 0; i <= mx; i++)
        {
            int j = i + x;
            if (j <= mx)
            {
                ans += l[i] * r[j];
            }
        }

        l[x]++;
    }

    std::cout << ans << "\n";
    return 0;
}
