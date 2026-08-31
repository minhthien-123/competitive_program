#include <bits/stdc++.h>
#define task "enum"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;
const int inf = 1e18;

std::vector<std::string> res;
void Try(int n, int l, int r, std::string str)
{
    if (l == n && r == n)
    {
        res.pb(str);
        return;
    }
    if (l < n)
    {
        Try(n, l + 1, r, str + "(");
    }
    if (r < l)
    {
        Try(n, l, r + 1, str + ")");
    }
}

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

    int n;
    std::cin >> n;

    if (n % 2 != 0)
    {
        return 0;
    }

    Try(n / 2, 0, 0, "");

    for (auto i : res)
    {
        std::cout << i << "\n";
    }

    return 0;
}
