#include <bits/stdc++.h>
#define task "nopalind"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 18;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

int l, r;
int n;
int digit[maxn + 7];
int dp[maxn + 7][11][11];

int f(int pos, int prelast, int last, bool flag)
{
    if (pos == n)
    {
        return 1;
    }

    int &memo = dp[pos][prelast][last];
    if (flag && memo != -1)
    {
        return memo;
    }

    int lim = flag ? 9 : digit[pos];
    int res = 0;
    for (int i = 0; i <= lim; i++)
    {
        if (i == last || i == prelast)
        {
            continue;
        }

        int nprelast = last;
        int nlast = i;
        if (last == 10 && i == 0)
        {
            nprelast = 10;
            nlast = 10;
        }

        res += f(pos + 1, nprelast, nlast, flag || (i < lim));
    }

    if (flag)
    {
        memo = res;
    }

    return res;
}

int g(int k)
{
    std::vector<int> tmp;
    if (k < 0)
    {
        return 0;
    }
    while (k > 0)
    {
        tmp.pb(k % 10);
        k /= 10;
    }
    std::reverse(tmp.begin(), tmp.end());
    n = tmp.size();
    for (int i = 0; i < n; i++)
    {
        digit[i] = tmp[i];
    }

    memset(dp, -1, sizeof dp);
    return f(0, 10, 10, 0);
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

    std::cin >> l >> r;
    std::cout << g(r) - g(l - 1);

    return 0;
}
