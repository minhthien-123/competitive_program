#include <bits/stdc++.h>
#define task "maxsub"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 35;
const int inf  = 1e18;

int n, m;
int a[maxn + 7];
int ans = 0;
std::vector<int> s1, s2;

void Try1(int i, int s)
{
    if (i > n / 2)
    {
        s1.pb(s);
        return;
    }
    Try1(i + 1, s % m);
    Try1(i + 1, (s + a[i]) % m);
}

void Try2(int i, int s)
{
    if (i > n)
    {
        int pos = (std::lower_bound(s1.begin(), s1.end(), m - s) - s1.begin()) - 1;
        ans = std::max(ans, s + s1[pos]);
        return;
    }
    Try2(i + 1, s % m);
    Try2(i + 1, (s + a[i]) % m);
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        a[i] %= m;
    }

    Try1(1, 0);
    std::sort(s1.begin(), s1.end());
    Try2(n / 2 + 1, 0);
    std::cout << ans;

    return 0;
}
