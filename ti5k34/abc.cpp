#include <bits/stdc++.h>
#define task "abc"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e3;
const int inf = 1e18;
int res;
int n;
int f[maxn + 7];
char a[maxn + 7], ans[maxn + 7];

bool valid(int i, int len)
{
    int tmp = i - len;
    return std::equal(a + tmp - len + 1, a + tmp + 1, a + i - len + 1);
}

bool check(int i)
{
    for (int j = 1; j <= i / 2; j++)
    {
        if (valid(i, j))
        {
            return false;
        }
    }
    return true;
}

void solve(int i)
{
    if (f[i - 1] + (n - i + 1) / 4 >= res)
    {
        return;
    }

    for (char c = 'A'; c <= 'C'; c++)
    {
        a[i] = c;
        if (!check(i))
        {
            continue;
        }

        f[i] = f[i - 1] + (c == 'C');
        if (i == n)
        {
            res = f[n];
            std::copy(a + 1, a + n + 1, ans + 1);
        }
        else
        {
            solve(i + 1);
        }
    }
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    if (std::fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    std::cin >> n;
    res = n;
    solve(1);

    for (int i = 1; i <= n; i++)
    {
        std::cout << ans[i];
    }

    std::cout << "\n" << res;

    return 0;
}
