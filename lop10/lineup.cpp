#include <bits/stdc++.h>
#define task "lineup"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

std::stack<long long> s;
long long n, i, a[1000005], dex[1000005], j, st[1000005], top;

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
    for (i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }

    //s.push(a[0]);

    for (i = 1; i <= n; i++){
        while (!s.empty() && a[s.top()] <= a[i]) s.pop();
        if (s.empty())
        {
            dex[i] = -1;
        }
        else
        {
            dex[i] = s.top() - 1;
        }

        s.push(i);
    }

    for (i = 1; i <= n; i++)
    {
        std::cout << dex[i] << " ";
    }
}
