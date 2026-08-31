#include <bits/stdc++.h>
using namespace std;

int a[1000005], dp[1000005];
int n, ans = INT_MIN;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("incseq.inp", "r", stdin);
    freopen("incseq.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++)
        dp[i] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (a[j] > a[i])
            {
                dp[j] = max(dp[j], dp[i] + 1);
            }
        }
    }

    for (int i = 1; i <= n; i++)
        ans = max(ans, dp[i]);

    cout << ans;
}
