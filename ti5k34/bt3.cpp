#include <bits/stdc++.h>
#define task "bt3"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e2;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;

int n;
std::string dp[maxn + 7][maxn + 7];
std::string s;

std::string sum(std::string a, std::string b)
{
    int i = a.size() - 1, j = b.size() - 1;
    int tmp = 0;
    std::string res = "";
    while (i >= 0 || j >= 0 || tmp)
    {
        int s = tmp;
        if (i >= 0)
        {
            s += a[i] - '0';
            i--;
        }
        if (j >= 0)
        {
            s += b[j] - '0';
            j--;
        }
        tmp = s / 10;
        res.pb((char)('0' + s % 10));
    }
    std::reverse(res.begin(), res.end());
    return res;
}

void solve(int n, bool flag)
{

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

    while (std::getline(std::cin, s))
    {

    }

    return 0;
}
