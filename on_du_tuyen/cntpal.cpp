#include <bits/stdc++.h>
#define task "cntpal"
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 5e3;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;

int n, q;
std::string s;
int f[maxn + 7][maxn + 7];

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
    n = s.size();
    s = " " + s;
    std::cin >> q;

    for (int k = 1; k <= n; k++)
    {
        int l = k, r = k;
        while (l >= 1 && r <= n && s[l] == s[r])
        {
            f[l][r]++;
            l--;
            r++;
        }

        l = k, r = k + 1;
        while (l >= 1 && r <= n && s[l] == s[r])
        {
            f[l][r]++;
            l--;
            r++;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        f[i][0] = f[0][i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            f[i][j] = f[i - 1][j] + f[i][j - 1] + f[i][j] - f[i - 1][j - 1];
        }
    }

    while (q--)
    {
        int l, r;
        std::cin >> l >> r;
        std::cout << f[r][r] - f[l - 1][r] - f[r][l - 1] + f[l - 1][l - 1] << "\n";
    }

    return 0;
}
