#include <bits/stdc++.h>
#define task "hoaqua"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e2;

int n, m, x = 0, y = 0;
int a[maxn + 7];
std::string str[maxn + 7];
std::map<std::string, int> s;
std::vector<int> v;

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
    }

    std::sort(a + 1, a + n + 1);

    for (int i = 1; i <= m; i++)
    {
        std::cin >> str[i];
        s[str[i]]++;
    }

    for (int i = 1; i <= m; i++)
    {
        if (s[str[i]] != 0)
        {
            v.pb(s[str[i]]);
        }
        s[str[i]] = 0;
    }

    std::sort(v.begin(), v.end(), std::greater<int>());

    // for (int i : v)
    // {
    //     std::cout << i << " ";
    // }

    int j = 0;
    for (int i : v)
    {
        x += i * a[++j];
    }

    j = n;
    for (int i : v)
    {
        y += i * a[j--];
    }

    std::cout << x << " " << y;

    return 0;
}
