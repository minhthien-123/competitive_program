#include <bits/stdc++.h>
#define task "gifts"
#define ing long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e6;
const int inf = 1e9;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

int n, m;
int b[maxn + 7];
int mx;
bool check[maxn + 7];
int par[maxn + 7];

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

    std::cin >> m;
    for (int i = 1; i <= m; i++)
    {
        std::cin >> b[i];
        mx = std::max(mx, b[i]);
    }
    std::cin >> n;
    for (int i = 1, x; i <= n; i++)
    {
        std::cin >> x;
        int cur = x;
        int cnt = 1;
        if (par[x] != 0)
        {
            cur = x;
            cnt = par[x] / x;
        }
        while (cur)
        {
            if (!check[x * cnt])
            {
                check[x * cnt] = 1;
                cur--;
            }
            if (x * (cnt + 1) > mx)
            {
                break;
            }
            cnt++;
        }
        par[x] = x * cnt;
    }

    int ans = 0;
    for (int i = 1; i <= m; i++)
    {
        if (check[b[i]])
        {
            ans++;
        }
    }

    std::cout << ans;

    return 0;
}
