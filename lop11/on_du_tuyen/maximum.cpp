#include <bits/stdc++.h>
#define task "maximum"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 2e5;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;

int n, m;
std::string s, t;
int l[maxn + 7], r[maxn + 7];

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> n >> m >> s >> t;
    s = " " + s;
    t = " " + t;

    int j = 1;
    for (int i = 1; i <= n && j <= m; i++)
    {
        if (s[i] == t[j])
        {
            l[j] = i;
            j++;
        }
    }

    j = m;
    for (int i = n; i >= 1 && j >= 1; i--)
    {
        if (s[i] == t[j])
        {
            r[j] = i;
            j--;
        }
    }

    int ans = 0;
    for (int i = 1; i < m; i++)
    {
        ans = std::max(ans, r[i + 1] - l[i]);
    }

    std::cout << ans;

    return 0;
}