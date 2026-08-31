#include <bits/stdc++.h>
#define task "sdkeq"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e6 + 7;
const int inf = 1e18;

int n, k;
int a[maxn], f[maxn];

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        a[i] += a[i - 1];
    }

    for (int i = 1; i <= k; i++)
    {
        int ans = -inf * (i != 1), res = -inf;
        for (int j = 1; j <= n; j++)
        {
            int tmp = f[j];
            f[j] = std::max(res, a[j] + ans);
            ans = std::max(ans, tmp - a[j]);
            res = std::max(res, f[j]);
        }
    }

    int res = -inf;
    for (int i = 1; i <= n; i++){
        res = std::max(res, f[i]);
    }

    std::cout << res << "\n";

    return 0;
}
