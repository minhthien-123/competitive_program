#include <bits/stdc++.h>
#define task "stove"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;

int n, k;
int a[maxn + 7], f[maxn + 7];

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
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }

    int ans = a[n] - a[1] + 1;
    std::vector<int> v;
    for (int i = 1; i < n; i++)
    {
        v.pb(a[i + 1] - a[i] - 1);
    }
    std::sort(v.begin(), v.end(), std::greater<int>());

    for (int i = 1; i < k; i++)
    {
        ans -= v[i - 1];
    }
    std::cout << ans;

    return 0;
}
