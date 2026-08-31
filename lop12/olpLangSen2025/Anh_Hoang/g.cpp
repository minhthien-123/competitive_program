#include <bits/stdc++.h>
#define task "g"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 2e5;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

int n, k;
ii a[maxn + 7];
int f[maxn + 7];
int check[maxn + 7];

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
        std::cin >> a[i].fi >> a[i].se;
    }
    for (int i = 1; i <= k; i++)
    {
        std::cin >> f[i];
    }

    std::sort(a + 1, a + n + 1);
    std::sort(f + 1, f + k + 1);
    f[k + 1] = inf;
    int j = 1, ans = 0;
    std::vector<int> v;
    for (int i = 1; i <= n; i++)
    {
        while (j < k and f[j + 1] < a[i].fi)
        {
            j++;
        }
        int d = std::min(abs(a[i].fi - f[j]), f[j + 1] - a[i].fi);
        if (d >= a[i].se)
        {
            ans += a[i].se;
        }
        else
        {
            if (d == abs(a[i].fi - f[j]) and d == f[j + 1] - a[i].fi)
            {
                ans += d;
                v.pb(j);
            }
            else if (d == abs(a[i].fi - f[j]))
            {
                ans += d;
                check[j]++;
            }
            else
            {
                ans += d;
                check[j + 1]++;
            }
        }
    }
    for (int x : v)
    {
        if (!check[x])
        {
            check[x + 1]++;
        }
    }
    for (int i = 1; i <= k; i++)
    {
        if (check[i])
        {
            ans++;
        }
    }
    std::cout << ans;

    return 0;
}
