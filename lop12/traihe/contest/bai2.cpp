#include <bits/stdc++.h>
#define int long long

const int maxn = 1e5;
const int INF  = 1e18;
int n, m, K;
int pre[maxn + 7], a[maxn + 7], b[maxn + 7];
int dp[55][maxn + 7];

int cost(int i, int j)
{
    int l = std::upper_bound(a + 1, a + n + 1, b[i]) - a;
    int r = std::upper_bound(a + 1, a + n + 1, b[j]) - a - 1;
    int mid = std::upper_bound(a + 1, a + n + 1, (b[i] + b[j]) / 2) - a - 1;
    mid = std::max(mid, l - 1);
    mid = std::min(mid, r);

    int costl = pre[mid] - pre[l - 1] - (mid - l + 1) * b[i];
    int costr = (r - mid) * b[j] - (pre[r] - pre[mid]);

    return costl + costr;
}

int cost1(int i)
{
    int r = std::upper_bound(a + 1, a + n + 1, b[i]) - a - 1;
    return r * b[i] - pre[r];
}

int cost2(int i)
{
    int l = std::upper_bound(a + 1, a + n + 1, b[i]) - a;
    return (pre[n] - pre[l - 1]) - (n - l + 1) * b[i];
}

void sub3()
{
    for (int i = 0; i <= K; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            dp[i][j] = INF;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        dp[1][i] = cost1(i);
    }

    for (int k = 2; k <= K; k++)
    {
        for (int i = k; i <= m; i++)
        {
            for (int j = k - 1; j < i; j++)
            {
                dp[k][i] = std::min(dp[k][i], dp[k - 1][j] + cost(j, i));
            }
        }
    }

    int ans = INF;
    for (int i = K; i <= m; i++)
    {
        ans = std::min(ans, dp[K][i] + cost2(i));
    }
    std::cout << ans;
}

struct DnC_DP
{
    int n, k;
    std::vector<std::vector<long long>> dp;
    const long long INF = 1e18;

    DnC_DP(int n, int k) : n(n), k(k)
    {
        dp.assign(k + 1, std::vector<long long>(n + 7, INF));
    }

    void compute(int dp_idx, int l, int r, int opt_l, int opt_r)
    {
        if (l > r)
            return;
        int mid = (l + r) / 2;
        int best_k = -1;
        long long best_val = INF;

        for (int j = opt_l; j <= std::min(mid - 1, opt_r); j++)
        {
            if (dp[dp_idx - 1][j] != INF)
            {
                long long cur_val = dp[dp_idx - 1][j] + cost(j, mid);
                if (cur_val < best_val)
                {
                    best_val = cur_val;
                    best_k = j;
                }
            }
        }

        dp[dp_idx][mid] = best_val;
        int safe_opt = (best_k == -1) ? opt_l : best_k;

        compute(dp_idx, l, mid - 1, opt_l, safe_opt);
        compute(dp_idx, mid + 1, r, safe_opt, opt_r);
    }

    void solve()
    {
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++)
        {
            dp[1][i] = cost1(i);
        }
        for (int i = 2; i <= k; i++)
        {
            compute(i, 1, n, 1, n - 1);
        }
    }
};

void sub4()
{
    DnC_DP dnc(m, K);
    dnc.solve();

    int ans = INF;
    for (int i = K; i <= m; i++)
    {
        ans = std::min(ans, dnc.dp[K][i] + cost2(i));
    }
    std::cout << ans;
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    std::cin >> n >> m >> K;

    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        std::cin >> b[i];
    }
    std::sort(a + 1, a + n + 1);
    std::sort(b + 1, b + m + 1);

    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1] + a[i];
    }

    if (n <= 1000 && K <= 50)
    {
        sub3();
    }
    else if (n <= 3000 && K <= 50)
    {
        sub4();
    }
    else
    {
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            int pos = std::lower_bound(b + 1, b + m + 1, a[i]) - b;
            int mn = INF;
            if (pos <= m)
            {
                mn = std::min(mn, b[pos] - a[i]);
            }
            if (pos > 1)
            {
                mn = std::min(mn, a[i] - b[pos - 1]);
            }
            ans += mn;
        }
        std::cout << ans;
    }
}
