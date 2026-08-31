#include <bits/stdc++.h>
#define task "btn1"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e3;
const int inf  = 1e18;

int dp[maxn + 7][maxn + 7];
std::string s;

int solve(int pos, int cnt, int ans)
{
    if (pos == s.size())
    {
        if (cnt == 0)
        {
            return ans;
        }
        return -inf;
    }

    if (dp[pos][cnt] != -1)
    {
        return dp[pos][cnt];
    }

    int res = -inf;
    if (s[pos] == '(')
    {
        if (cnt + 1 <= s.size())
        {
            res = std::max(res, solve(pos + 1, cnt + 1, std::max(ans, cnt + 1)));
        }
    }
    else if (s[pos] == ')')
    {
        if (cnt > 0)
        {
            res = std::max(res, solve(pos + 1, cnt - 1, ans));
        }
    }
    else
    {
        int tmp1 = cnt + 1;
        if (tmp1 <= s.size())
        {
            res = std::max(res, solve(pos + 1, tmp1, std::max(ans, tmp1)));
        }

        if (cnt > 0)
        {
            res = std::max(res, solve(pos + 1, cnt - 1, ans));
        }
    }

    dp[pos][cnt] = res;
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

    std::cin >> s;
    if (s.size() <= 1000)
    {
        std::memset(dp, -1, sizeof(dp));
        std::cout << solve(0, 0, 0) << '\n';
    }
    else
    {
        std::cout << s.size() / 2;
    }

    return 0;
}