#include <bits/stdc++.h>
#define task "lucky13"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 15;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

int a, b;
int digit[maxn + 7];
int dp[2][maxn + 7];
int n;

int f(int pos, bool flag, int last)
{
    if (pos == n)
    {
        return 1;
    }

    int &memo = dp[last][pos];
    if (flag && memo != -1)
    {
        return memo;
    }

    int lim = flag ? 9 : digit[pos];
    int res = 0;
    for (int i = 0; i <= lim; i++)
    {
        if (last == 1 && i == 3)
        {
            continue;
        }
        res += f(pos + 1, flag || (i < lim), i == 1);
    }

    if (flag)
    {
        memo = res;
    }
    return res;
}

int g(int k)
{
    if (k < 0)
    {
        return 0;
    }
    std::vector<int> tmp;
    if (k == 0)
    {
        tmp.pb(0);
    }
    while (k > 0)
    {
        tmp.pb(k % 10);
        k /= 10;
    }
    std::reverse(tmp.begin(), tmp.end());
    n = tmp.size();
    for (int i = 0; i < tmp.size(); i++)
    {
        digit[i] = tmp[i];
    }

    memset(dp, -1, sizeof dp);
    return f(0, 0, 0);
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

    while (std::cin >> a >> b)
    {
        int ans = g(b) - g(a - 1);
    
        std::cout << ans << '\n';
    }



    return 0;
}
