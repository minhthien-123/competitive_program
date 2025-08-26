#include <bits/stdc++.h>
#define task "float"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e6;

int n, k;
int a[maxn + 7];

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> n >> k;
    a[0] = 0;y
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        a[i] += a[i - 1];
    }

    /*for (int i = 1; i <= n; i++)
    {
        std::cout << a[i] << " ";
    }
    std::cout << "\n";*/

    int cnt = 0;
    for (int i = 0; i <= n; i++)
    {
        cnt += std::binary_search(a + 1, a + n + 1, a[i] + k);
    }
    std::cout << cnt << "\n";

    return 0;
}