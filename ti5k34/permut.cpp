#include <bits/stdc++.h>
#define task "binstr"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;
const int inf = 1e18;

int n;
int mx;

int ans[maxn + 7];
bool f[maxn + 7];

void Try(int i)
{
    for (int j = 1; j <= mx; j++)
    {
        if (j - ans[i - 1] > 0)
        {
            f[j] = true;
            ans[i] = j;
            if (i == n)
            {
                for (int k = 1; k <= n; k++)
                {
                    std::cout << ans[k] << " ";
                }
                std::cout << "\n";
            }
            else
            {
                Try(i + 1);
            }
            f[j] = false;
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
        std::freopen(task ".inp", "r", stdin);
        std::freopen(task ".out", "w", stdout);
    }

    std::cin >> mx >> n;

    Try(1);

    return 0;
}
