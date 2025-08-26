#include <bits/stdc++.h>
#define task "us"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e6;
const int inf  = 1e18;

int t;
int cnt_div[maxn + 7], sum_div[maxn + 7];

void init()
{
    for (int i = 1; i <= maxn; i++)
    {
        for (int j = i; j <= maxn; j += i)
        {
            cnt_div[j]++;
            sum_div[j] += i;
        }
    }

    for (int i = 1; i <= maxn; i++)
    {
        cnt_div[i] += cnt_div[i - 1];
        sum_div[i] += sum_div[i - 1];
    }
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

    init();

    std::cin >> t;
    while (t--)
    {
        int a, b;
        std::cin >> a >> b;
        std::cout << cnt_div[b] - cnt_div[a - 1] << " " << sum_div[b] - sum_div[a - 1] << "\n";
    }

    return 0;
}
