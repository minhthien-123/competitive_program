#include <bits/stdc++.h>
#define task "kethop"
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

int x, y, z;
int n;
int a[maxn + 7];
int pre[maxn + 7], suf[maxn + 7];

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

    std::cin >> x >> y >> z;
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }

    pre[1] = a[1];
    for (int i = 2; i <= n; i++)
    {
        pre[i] = std::max(pre[i - 1], a[i]);
    }

    suf[n] = a[n];
    for (int i = n - 1; i >= 1; i--)
    {
        suf[i] = std::max(suf[i + 1], a[i]);
    }

    int ans = -inf;
    for (int j = 2; j <= n - 1; j++)
    {
        int ai = pre[j - 1];
        int ak = suf[j + 1];
        ans = std::max(ans, x * ai + y * a[j] + z * ak);
    }

    std::cout << ans;

    return 0;
}
