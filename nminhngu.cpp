#include <bits/stdc++.h>
#define task "main"
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

int n, k;

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

    std::cin >> n >> k;

    int s = 0;
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        int cnt = (i <= n ? i : 2 * n - i);
        int l = s + 1;
        int r = s + cnt;
        s += cnt;

        if (l <= k && k <= r)
        {
            std::cout << (r - l + 1) * (r + l) / 2;
            return 0;
        }
    }

    return 0;
}
