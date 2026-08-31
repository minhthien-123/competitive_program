#include <bits/stdc++.h>
#define task "kd"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 5e5;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

int n;
int a[maxn + 7];

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
    int p = 0, m = 0, z = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        if (x > 0)
        {
            p++;
        }
        else if (x < 0)
        {
            m++;
        }
        else
        {
            z++;
        }
    }

    int ans = z * (n - z) + (z * (z - 1) / 2);
    ans += p * m;

    std::cout << ans;

    return 0;
}
