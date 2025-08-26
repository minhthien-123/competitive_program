#include <bits/stdc++.h>
#define task "choices"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e3 + 7;
const int mod  = 1e9 + 7;
int m, n;
int c[maxn][maxn];

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    for (int i = 0; i <= 1000; i++)
    {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++)
        {
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
        }
    }

    int t;
    std::cin >> t;
    while (t--)
    {
        int n, k;
        std::cin >> n >> k;
        std::cout << c[n][k] << "\n";
    }

    return 0;
}
