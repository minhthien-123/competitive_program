#include <bits/stdc++.h>
#define task "ksack1"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e3;
const int inf = 1e18;

int n, m;
int w[maxn], v[maxn];

struct ksack
{
    int val;
    std::vector<int> vec;
};

ksack solve(int pos, int W)
{
    if (pos > n)
    {
        return {0, {}};
    }

    ksack tmp1 = solve(pos + 1, W);

    ksack tmp2 = {0, {}};
    if (W + w[pos] <= m)
    {
        tmp2 = solve(pos + 1, W + w[pos]);
        tmp2.val += v[pos];
        tmp2.vec.push_back(pos);
    }

    if (tmp2.val > tmp1.val)
    {
        return tmp2;
    }
    else
    {
        return tmp1;
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

    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> w[i] >> v[i];
    }

    ksack ans = solve(1, 0);
    std::cout << ans.val << "\n";
    std::reverse(ans.vec.begin(), ans.vec.end());
    // int s = 0;
    for (int i : ans.vec)
    {
        std::cout << i << " ";
        // s += v[i];
    }
    std::cout << "\n";
    // std::cout << s << "\n";

    return 0;
}
