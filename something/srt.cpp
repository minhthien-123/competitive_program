#include <bits/stdc++.h>
#define task "srt"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 3e5 + 7;

int n;
int a[maxn], f[maxn], g[maxn];
int bit1[maxn], bit2[maxn];

void update1(int x, int val) {
    for (; x > 0; x -= x & (-x))
    {
        bit1[x] = std::max(bit1[x], val);
    }
}

void update2(int x, int val) {
    for (; x <= n; x += x & (-x))
    {
        bit2[x] = std::max(bit2[x], val);
    }
}

int query1(int x) {
    int ans = 0;
    for (; x <= n; x += x & (-x))
    {
        ans = std::max(ans, bit1[x]);
    }
    return ans;
}

int query2(int x) {
    int ans = 0;
    for (; x > 0; x -= x & (-x))
    {
        ans = std::max(ans, bit2[x]);
    }
    return ans;
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

    std::vector<int> v;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        v.push_back(a[i]);
    }
    std::sort(v.begin(), v.end());

    for (int i = 1; i <= n; i++)
    {
        a[i] = std::lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
    }

    for (int i = n; i >= 1; i--) {
        f[i] = 1 + query1(a[i] + 1);
        g[i] = 1 + query2(a[i] - 1);
        update1(a[i], f[i]); update2(a[i], g[i]);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = std::max(ans, f[i] + g[i] - 1);
    }
    std::cout << ans;

    return 0;
}
