#include <bits/stdc++.h>
#define task "i"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 3e5;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

int n;
int a[maxn + 7];
int L[maxn + 7], R[maxn + 7];
int st[4 * maxn + 7];

void build(int id, int l, int r)
{
    if (l == r)
    {
        st[id] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    st[id] = std::max(st[id * 2], st[id * 2 + 1]);
}

int getMax(int id, int l, int r, int u, int v)
{
    if (v < l || r < u)
    {
        return 0;
    }
    if (u <= l && r <= v)
    {
        return st[id];
    }
    int mid = (l + r) / 2;
    return std::max(getMax(id * 2, l, mid, u, v), getMax(id * 2 + 1, mid + 1, r, u, v));
}

int getLeft(int id, int l, int r, int u, int v, int val)
{
    if (v < l || u > r || st[id] < val)
    {
        return -1;
    }
    if (l == r)
    {
        return l;
    }
    int m = (l + r) >> 1;
    int t = getLeft(id << 1 | 1, m + 1, r, u, v, val);
    if (t != -1)
    {
        return t;
    }
    return getLeft(id << 1, l, m, u, v, val);
}
int getRight(int id, int l, int r, int u, int v, int val)
{
    if (v < l || u > r || st[id] < val)
    {
        return -1;
    }
    if (l == r)
    {
        return l;
    }
    int m = (l + r) >> 1;
    int t = getRight(id << 1, l, m, u, v, val);
    if (t != -1)
    {
        return t;
    }
    return getRight(id << 1 | 1, m + 1, r, u, v, val);
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
    }

    std::stack<int> s;
    for (int i = 1; i <= n; i++)
    {
        while (!s.empty() && a[s.top()] >= a[i])
        {
            s.pop();
        }
        if (s.empty())
        {
            L[i] = 0;
        }
        else
        {
            L[i] = s.top();
        }
        s.push(i);
    }
    while (!s.empty())
    {
        s.pop();
    }
    for (int i = n; i >= 1; i--)
    {
        while (!s.empty() && a[s.top()] > a[i])
        {
            s.pop();
        }
        if (s.empty())
        {
            R[i] = n + 1;
        }
        else
        {
            R[i] = s.top();
        }
        s.push(i);
    }

    build(1, 1, n);

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int sum = (i - L[i]) * (R[i] - i);

        int mx = getMax(1, 1, n, L[i] + 1, R[i] - 1);
        int lim = mx / a[i];

        for (int k = 1; k <= lim; k++)
        {
            int val = k * a[i];
            int l = getLeft(1, 1, n, L[i] + 1, i, val);
            if (l == -1)
            {
                l = L[i];
            }
            int r = getRight(1, 1, n, i, R[i] - 1, val);
            if (r == -1)
            {
                r = R[i];
            }

            ans += (sum - (i - l) * (r - i));
        }
    }

    std::cout << ans << "\n";
    return 0;
}