#include <bits/stdc++.h>
#define task "main"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 5e4;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;

int n;
bool f[maxn + 7];
int a[maxn + 7], b[maxn + 7];
int l[maxn + 7], r[maxn + 7];

std::set<int> s1;
std::set<int, std::greater<int>> s2;
int cnt = 0;

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> b[i];
        f[b[i]] = true;
    }

    for (int i = 1; i <= 2 * n; i++)
    {
        if (!f[i])
        {
            s1.ins(i);
            s2.ins(i);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        auto it = s1.lower_bound(b[i]);
        if (it != s1.end())
        {
            s1.erase(it);
            l[i] = l[i - 1] + 1;
        }
        else
        {
            l[i] = l[i - 1];
        }
    }

    for (int i = n; i >= 1; i--)
    {
        auto it = s2.lower_bound(b[i]);
        if (it != s2.end())
        {
            s2.erase(it);
            r[i] = r[i + 1] + 1;
        }
        else
        {
            r[i] = r[i + 1];
        }
    }

    int ans = r[1];
    for (int i = 1; i <= n; i++)
    {
        ans = std::max(ans, l[i] + r[i + 1]);
    }

    std::cout << ans << '\n';

    return 0;
}
