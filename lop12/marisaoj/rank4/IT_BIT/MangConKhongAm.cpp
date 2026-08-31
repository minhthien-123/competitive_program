#include <bits/stdc++.h>
#define task ""
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5 + 7;

int n, bit[maxn];
int res, a[maxn];
std::vector<int> ans;

void add(int x)
{
    x++;
    while (x <= (int)(ans.size()))
    {
        bit[x]++;
        x += x & -x;
    }
}

int get(int x)
{
    int sum = 0;
    x++;
    while (x)
    {
        sum += bit[x];
        x -= x & -x;
    }
    return sum;
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

    int x;
    std::cin >> n;
    ans.pb(0);

    for (int i = 1; i <= n; i++)
    {
        std::cin >> x;
        a[i] = a[i - 1] + x;
        ans.pb(a[i]);
    }

    std::sort(ans.begin(), ans.end());
    ans.resize(std::unique(ans.begin(), ans.end()) - ans.begin());

    for (int i = 0; i <= n; i++){
        if (i != 0)
        {
            int high = std::upper_bound(ans.begin(), ans.end(), a[i]) - ans.begin();
            res += get(high - 1);
        }
        x = std::lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin();
        add(x);
    }
    std::cout << res;
    return 0;
}
