#include <bits/stdc++.h>
#define task "lcsk"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e3;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;

int n, m, k;
int a[maxn + 7], b[maxn + 7];
ii par[maxn + 7][maxn + 7];
int dp[maxn + 7][maxn + 7];
std::deque<ii> dq[maxn + 7];
ii st[4 * maxn + 7];

void update(int id, ii val)
{
    int tmp = 
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> m >> n >> k;
    for (int i = 1; i <= m; i++)
    {
        std::cin >> a[i];
    }
    for (int j = 1; j <= n; j++)
    {
        std::cin >> b[j];
    }



    return 0;
}
