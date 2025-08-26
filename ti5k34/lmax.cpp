#include <bits/stdc++.h>
#define task "lmax"
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

int n, k;
int a[maxn + 7][maxn + 7];
std::unordered_map<int, int> cnt, pos[maxn + 7];
std::vector<int> v;
int dp[maxn + 7];

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

    std::cin >> n >> k;
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            std::cin >> a[i][j];
        }
    }

    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cnt[a[i][j]]++;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (cnt[a[1][i]] == k)
        {
            v.pb(a[1][i]);
        }
    }

    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            pos[i][a[i][j]] = j;
        }
    }

    if (v.size() == 0)
    {
        std::cout << 0;
        return 0;
    }

    for (int i = 0; i < v.size(); i++)
    {
        dp[i] = 1;
    }

    int ans = 1;

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            bool check = true;
            for (int t = 1; t <= k; t++)
            {
                if (pos[t][v[j]] >= pos[t][v[i]])
                {
                    check = false;
                    break;
                }
            }
            if (check)
            {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
        ans = std::max(ans, dp[i]);
    }

    std::cout << ans;

    return 0;
}
