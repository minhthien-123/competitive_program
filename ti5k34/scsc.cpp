#include <bits/stdc++.h>
#define task "scsc"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e3 + 7;
int n;
int a[maxn], f[maxn];
std::unordered_map<int, int> mp;
int ans = 1;

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
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        a[i] += a[i - 1];
    }

    for (int i = 1; i <= n; i++)
    {
        std::cout << a[i] << " ";
    }

    return 0;
}

// 1 2 3 7 4 6 5 6 5 4
// 1 2 3   4   5 6 5 4