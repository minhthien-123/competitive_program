#include <bits/stdc++.h>
#define task "phatqua"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e6;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

int n, k;
int a[maxn + 7];
std::deque<int> dq;
int f[maxn + 7], sum[maxn + 7];
bool check[maxn + 7];
int lmax[maxn + 7], rmax[maxn + 7];

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
        lmax[i] = -inf;
        rmax[i] = -inf;
    }

    int m = n - k + 1;
    for (int i = 1; i <= n; i++)
    {
        f[i] = f[i - 1] + a[i];
    }

    for (int i = 1; i <= m; i++)
    {
        sum[i] = f[i + k - 1] - f[i - 1];
    }

    lmax[1] = sum[1];
    for (int i = 2; i <= m; i++)
    {
        lmax[i] = std::max(lmax[i - 1], sum[i]);
    }
    rmax[m] = sum[m];
    for (int i = m - 1; i >= 1; i--)
    {
        rmax[i] = std::max(rmax[i + 1], sum[i]);
    }

    /*for (int i = 1; i <= n; i++)
    {
        std::cout << lmax[i] << " ";
    }*/

    int ans = inf;
    for (int i = 1; i <= m; ++i)
    {
        int lans = -inf, rans = -inf;
        if (i - k >= 1)
        {
            lans = lmax[i - k];
        }
        if (i + k <= m)
        {
            rans = rmax[i + k];
        }
        ans = std::min(ans, std::max(lans, rans));
    }

    std::cout << ans;

    return 0;
}
