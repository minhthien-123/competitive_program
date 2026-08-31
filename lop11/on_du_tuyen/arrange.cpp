#include <bits/stdc++.h>
#define task "arrange"
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

int q;
int n, m, k;

bool check(int x)
{
    int L = std::min(k - 1, x - 1);
    int R = std::min(n - k, x - 1);

    long long sumL = (L + 1) * x - L * (L + 1) / 2;
    long long sumR = (R + 1) * x - R * (R + 1) / 2;
    long long sum = sumL + sumR - x;
    return sum <= m;
}

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

    std::cin >> q;
    while (q--)
    {
        std::cin >> n >> m >> k;

        int l = 1, r = m, ans = 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (check(mid))
            {
                ans = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }

        std::cout << (m - ans) << "\n";
    }

    return 0;
}
