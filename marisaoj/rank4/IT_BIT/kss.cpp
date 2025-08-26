#include <bits/stdc++.h>
#define task "kss"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5 + 7;
const int inf  = 1e18;

int n, k;
int a[maxn], bit[2 * maxn], pre[maxn];

void update(int id)
{
    for (id; id <= n; id += id & -id)
    {
        bit[id]++;
    }
}

int get(int id)
{
    int ans = 0;
    for (id; id > 0; id -= id & -id)
    {
        ans += bit[id];
    }

    return ans;
}

bool check(int x) {
    std::fill(bit, bit + n + 1, 0);

    int cnt = 0, tmp = 0;
    for (int i = 1; i <= n; i++) {
        update(std::lower_bound(pre + 1, pre + 1 + n, tmp) - pre);
        tmp += a[i];
        cnt += get(std::upper_bound(pre + 1, pre + 1 + n, tmp - x) - pre - 1);
    }

    return (cnt >= k);
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

    std::cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        pre[i] = pre[i - 1] + a[i - 1];
    }

    std::sort(pre + 1, pre + n + 1);

    int l = -inf, r = inf, ans = 0;

    while (l <= r)
    {
        int mid = l + r >> 1;
        if (check(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    std::cout << ans;

    return 0;
}
