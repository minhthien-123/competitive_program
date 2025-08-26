#include <bits/stdc++.h>
#define task "ipara"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert
const int maxn = 1e5;
const int inf  = 1e18;

int n, s = 0, d = 0;
int ans[maxn + 7];

void Try(int i, int sum)
{
    if (sum == 0)
    {
        for (int k = 1; k < i; k++)
        {
            std::cout << ans[k] << " ";
        }
        d++;
        std::cout << "\n";
        return;
    }

    int pos;
    if (i == 1)
    {
        pos = 1;
    }
    else
    {
        pos = ans[i - 1];
    }


    for (int j = pos; j <= sum; j++)
    {
        ans[i] = j;
        Try(i + 1, sum - j);
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

    std::cin >> n;

    Try(1, n);

    std::cout << d;

    return 0;
}

