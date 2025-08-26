#include <bits/stdc++.h>
#define task "PALIND5"
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

int n;
std::string a;
int dp[maxn + 7][maxn + 7];

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

    std::cin >> a;
    int n = a.size();
    a = " " + a;

    for (int i = 1; i <= n; i++)
    {
        dp[i][i] = 0;
    }

    for (int len = 2; len <= n; len++)
    {
        for (int i = 1; i + len - 1 <= n; i++)
        {
            int j = i + len - 1;
            if (a[i] == a[j])
            {
                if (len == 2)
                {
                    dp[i][j] = 0;
                }
                else
                {
                    dp[i][j] = dp[i + 1][j - 1];
                }
            }
            else
            {
                dp[i][j] = std::min(dp[i][j - 1], dp[i + 1][j]) + 1;
            }
        }
    }

    int l = 1, r = n;
    std::string s1 = "", s2 = "";
    while (l < r)
    {
        if (a[l] == a[r])
        {
            s1 += a[l];
            s2 = a[r] + s2;
            l++;
            r--;
        }
        else if (dp[l + 1][r] < dp[l][r - 1])
        {
            s1 += a[l];
            s2 = a[l] + s2;
            l++;
        }
        else
        {
            s1 += a[r];
            s2 = a[r] + s2;
            r--;
        }
    }
    if (l == r)
    {
        s1 += a[l];
    }

    std::cout << s1 + s2;

    return 0;
}