#include <bits/stdc++.h>
#define task "nextbin"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;
const int inf  = 1e18;

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
    for (int i = 1; i <= k; i++)
    {
        std::cin >> a[i];
    }

    int mx = n;
    int id = k;
    while (id > 1 && (a[id] == mx))
    {
        mx = a[id] - 1;
        id--;
        //std::cout << a[i] << " " << mx << "\n";
    }

    // std::cout << id << "\n";

    a[id]++;
    for (int i = id + 1; i <= k; i++)
    {
        a[i] = a[i - 1] + 1;
    }

    if (a[k] > n)
    {
        std::cout << "NOTAVAILABLE";
        return 0;
    }

    for (int i = 1; i <= k; i++)
    {
        std::cout << a[i] << " ";
    }

    return 0;
}
