#include <bits/stdc++.h>
#define task "bin"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;
const int inf  = 1e18;

int n;

std::string solve(int x)
{
    std::string res = "";
    while (x > 0)
    {
        res += std::to_string(x % 2);
        x /= 2;
    }
    std::reverse(res.begin(), res.end());
    return res;
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

    while (std::cin >> n)
    {
        std::cout << solve(n) << "\n";
    }

    return 0;
}
