#include <bits/stdc++.h>
#define task "btn2"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e3;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

std::string s;
int mx;

bool vis[maxn + 7][maxn + 7][2];
std::string dp[maxn + 7][maxn + 7][2];

std::string btn(std::string a, std::string b)
{
    if (a == "#")
        return b;
    if (b == "#")
        return a;
    return std::max(a, b);
}

std::string solve(int i, int d, bool flag)
{
    if (d < 0 || d > mx)
    {
        return "#";
    }

    if (i == s.size())
    {
        if (d == 0 && flag)
        {
            return "";
        }
        return "#";
    }

    if (vis[i][d][flag])
    {
        return dp[i][d][flag];
    }
    vis[i][d][flag] = true;
    std::string res = "#";

    char c = s[i];
    if (c == '(')
    {
        if (d + 1 <= mx)
        {
            bool nflag = flag || ((d + 1) == mx);
            std::string tmp = solve(i + 1, d + 1, nflag);
            if (tmp != "#")
            {
                res = "(" + tmp;
            }
        }
    }
    else if (c == ')')
    {
        if (d - 1 >= 0)
        {
            std::string tmp = solve(i + 1, d - 1, flag);
            if (tmp != "#")
            {
                res = ")" + tmp;
            }
        }
    }
    else
    {
        std::string cur = "#";
        if (d - 1 >= 0)
        {
            std::string tmp = solve(i + 1, d - 1, flag);
            if (tmp != "#")
            {
                cur = ")" + tmp;
            }
        }
        res = btn(res, cur);

        if (d + 1 <= mx)
        {
            bool nflag = flag || ((d + 1) == mx);
            std::string tmp = solve(i + 1, d + 1, nflag);
            if (tmp != "#")
            {
                res = btn(res, "(" + tmp);
            }
        }
    }

    return dp[i][d][flag] = res;
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

    std::cin >> s;

    int l = 0, r = 0;
    for (char c : s)
    {
        if (c == '(')
        {
            l++;
        }
        else if (c == ')')
        {
            r++;
        }
    }
    int k = s.size() / 2 - l;
    int b = 0;
    mx = 0;

    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        if (c == '(')
        {
            b++;
        }
        else if (c == ')')
        {
            b--;
            mx = std::max(mx, b);
        }
        else
        {
            if (k > 0)
            {
                b++;
                k--;
            }
            else
            {
                b--;
            }
        }
        mx = std::max(mx, b);
    }

    std::string res = solve(0, 0, 0);
    std::cout << res << "\n";

    return 0;
}
