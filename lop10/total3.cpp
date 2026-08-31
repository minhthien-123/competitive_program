#include <bits/stdc++.h>
#define task "total3"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 5e3 + 7;
const int tt = 2e6;
int n;
int a[maxn], ans[maxn], t[2 * tt];

signed main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r")){
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }

    for (int i = 1; i <= n; i++)
    {
        ans[i] = 0;
    }

    for (int i = -tt; i <= tt; i++)
    {
        t[i + tt] = 0;
    }

    for (int k = 3; k <= n - 1; k++)
    {
        for (int i = 1; i <= k - 2; i++)
        {
            t[a[i] + a[k - 1] + tt]++;
        }
        for (int i = k + 1; i <= n; i++)
        {
            ans[i] += t[a[i] - a[k] + tt];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        std::cout << ans[i] << " ";
    }

    return 0;
}