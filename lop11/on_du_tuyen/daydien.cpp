#include <bits/stdc++.h>
#define task "daydien"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

int n;
int a[maxn + 7];
int dp1[maxn + 7], f1[maxn + 7], dp2[maxn + 7], f2[maxn + 7];
ii st1[4 * maxn + 7], st2[4 * maxn + 7];
std::vector<int> vec;

void update(int id, int l, int r, int pos, ii val, ii st[])
{
    if (pos < l || pos > r)
    {
        return;
    }
    if (l == r)
    {
        if (val.fi > st[id].fi)
        {
            st[id] = val;
        }
        return;
    }
    int mid = (l + r) / 2;
    update(id * 2, l, mid, pos, val, st);
    update(id * 2 + 1, mid + 1, r, pos, val, st);
    st[id] = std::max(st[id * 2], st[id * 2 + 1]);
}

ii get(int id, int l, int r, int u, int v, ii st[])
{
    if (v < l || r < u)
    {
        return {0, -1};
    }
    if (u <= l && r <= v)
    {
        return st[id];
    }
    int mid = (l + r) / 2;
    return std::max(get(id * 2, l, mid, u, v, st), get(id * 2 + 1, mid + 1, r, u, v, st));
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    if (std::fopen(task ".inp", "r"))
    {
        std::freopen(task ".inp", "r", stdin);
        std::freopen(task ".out", "w", stdout);
    }

    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        vec.pb(a[i]);
    }
    std::sort(vec.begin(), vec.end());
    vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
    int m = vec.size();

    for (int i = 1; i <= 4 * m; i++)
    {
        st1[i] = ii(0, -1);
        st2[i] = ii(0, -1);
    }

    for (int i = 1; i <= n; i++)
    {
        int it = std::lower_bound(vec.begin(), vec.end(), a[i]) - vec.begin() + 1;
        ii tmp;
        if (it < m)
        {
            tmp = get(1, 1, m, it + 1, m, st1);
        }
        else
        {
            tmp = ii(0, -1);
        }
        dp1[i] = tmp.fi + 1;
        f1[i] = tmp.se;
        update(1, 1, m, it, {dp1[i], i}, st1);
    }

    for (int i = n; i >= 1; i--)
    {
        int it = std::lower_bound(vec.begin(), vec.end(), a[i]) - vec.begin() + 1;
        ii tmp;
        if (it < m)
        {
            tmp = get(1, 1, m, it + 1, m, st2);
        }
        else
        {
            tmp = ii(0, -1);
        }
        dp2[i] = tmp.fi + 1;
        f2[i] = tmp.se;
        update(1, 1, m, it, {dp2[i], i}, st2);
    }

    int ans = 0, pos = -1;
    for (int i = 1; i <= n; i++)
    {
        int len = dp1[i] + dp2[i] - 1;
        if (len > ans)
        {
            ans = len;
            pos = i;
        }
    }

    if (ans == 0)
    {
        std::cout << 0;
        return 0;
    }

    std::vector<int> l, r;
    for (int i = pos; i != -1; i = f1[i])
    {
        l.pb(a[i]);
    }
    std::reverse(l.begin(), l.end());
    for (int i = f2[pos]; i != -1; i = f2[i])
    {
        r.pb(a[i]);
    }

    std::vector<int> vec;

    for (int x : l)
    {
        vec.pb(x);
    }
    for (int x : r)
    {
        vec.pb(x);
    }

    bool flag = true;
    int i = 1;
    while (vec[i] < vec[i - 1] && i < vec.size())
    {
        i++;
    }

    if (i == 1 || i == vec.size())
    {
        std::cout << 0;
        return 0;
    }

    std::cout << ans << "\n";
    for (int x : vec)
    {
        std::cout << x << " ";
    }

    return 0;
}
