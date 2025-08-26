#include <bits/stdc++.h>
#define task "mathuat"
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

int t;
int n;
int a[maxn + 7];
int p, q;

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> t;
    while (t--)
    {
        std::cin >> n >> p >> q;
        for (int i = 1; i <= n; i++)
        {
            std::cin >> a[i];
        }

        q++;

        std::sort(a + 1, a + n + 1);

        int ans = a[n];

        int l = 1, r = n - 1;

        while (l <= r && (p > 0 || q > 0))
        {
            if (p > 0)
            {
                if (q > 0)
                {
                    if (abs(a[r]) > abs(a[l]))
                    {
                        ans += a[r];
                        r--;
                        p--;
                    }
                    else
                    {
                        ans -= a[l];
                        l++;
                        q--;
                    }
                }
                else
                {
                    ans += a[r];
                    r--;
                    p--;
                }
            }
            else
            {
                ans -= a[l];
                l++;
                q--;
            }

            std::cout << ans << " " << p << " " << q << "\n";
        }

        std::cout << ans << "\n";
    }

    return 0;
}
