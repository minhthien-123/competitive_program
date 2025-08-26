#include <bits/stdc++.h>
#define task "food"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e6;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

int m, n;
int a[maxn + 7];
int pre[maxn + 7], prf[maxn + 7];
int ans = 0;
int sum, res;
int l, r;

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    if (std::fopen(task ".inp", "R"))
    {
        std::freopen(task ".inp", "R", stdin);
        std::freopen(task ".ans", "w", stdout);
    }

    std::cin >> m >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];

    pre[0] = 0;
    prf[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        pre[i] = (pre[i - 1] + (a[i] % m) + m) % m;
        prf[i] = prf[i - 1] + a[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            if (pre[j] - pre[i - 1] == 0)
            {
                ans++;
                int len = j - i + 1;
                int tmp = prf[j] - prf[i - 1];
                if (len > res || (len == res && tmp > sum))
                {
                    sum = tmp;
                    res = len;
                    l = i;
                    r = j;
                }
            }
        }
    }

    std::cout << res << "\n" << l << " " << r;

    return 0;
}
