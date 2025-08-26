#include <bits/stdc++.h>
#define task "summax"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5; // 10^5
const int inf = 1e9;  // 10^9

struct tree
{
    int pre, suf, sum, val;
};

int n, k;
int a[maxn + 7], pre[maxn + 7], f[maxn + 7];
tree st[4 * maxn + 7];
std::deque<int> dq;

tree merge(tree a, tree b)
{
    tree res;
    res.pre = std::max(a.pre, a.sum + b.pre);
    res.suf = std::max(b.suf, b.sum + a.suf);
    res.sum = a.sum + b.sum;
    res.val = std::max({a.val, b.val, a.suf + b.pre});
    return res;
}

void build(int id, int l, int r)
{
    if (l == r)
    {
        st[id] = {a[l], a[l], a[l], a[l]};
        return;
    }
    int mid = (l + r) >> 1;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    st[id] = merge(st[id * 2], st[id * 2 + 1]);
}

tree get(int id, int l, int r, int u, int v)
{
    if (v < l || r < u)
    {
        return {-inf, -inf, 0, -inf};
    }
    if (u <= l && r <= v)
    {
        return st[id];
    }

    int mid = (l + r) >> 1;
    tree left = get(id * 2, l, mid, u, v);
    tree right = get(id * 2 + 1, mid + 1, r, u, v);
    return merge(left, right);
}

int sub0()
{
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= i + k - 1; j++)
        {
            int sum = 0;
            for (int s = i; s <= j; s++)
            {
                sum += a[s];
            }
            ans = std::max(ans, sum);
        }
    }

    return ans;
}

int sub1()
{
    int ans = LLONG_MIN;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= i + k - 1; j++)
        {
            ans = std::max(ans, pre[j] - pre[i - 1]);
        }
    }

    return ans;
}

int sub2()
{
    build(1, 1, n);
    int ans = LLONG_MIN;
    for (int i = 1; i <= n - k + 1; i++)
    {
        ans = std::max(ans, get(1, 1, n, i, i + k - 1).val);
    }

    return ans;
}

int sub2_fixed()
{
    while (dq.size())
    {
        dq.pop_front();
    }

    for (int i = 1; i <= n; i++) {
        while (dq.size() && pre[dq.back()] >= pre[i]) dq.pop_back();

        dq.push_back(i);

        if (dq.front() + k <= i) dq.pop_front();

        if (i >= k) f[i] = pre[dq.front()];
    }

    int ans = LLONG_MIN;

    // std::cout << "\n";
    // for (int i = 1; i <= n; i++)
    // {
    //     std::cout << pre[i] << " ";
    // }
    // std::cout << "\n";
    // for (int i = 1; i <= n; i++)
    // {
    //     std::cout << f[i] << " ";
    // }
    // std::cout << "\n";

    for (int i = 1; i <= n; i++)
    {
        ans = std::max(ans, pre[i] - f[i - 1]);
    }

    return ans;
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

    std::cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }

    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1] + a[i];
    }

    std::cout << sub0() << "\n";
    std::cout << sub1() << " " << sub2() << " " << sub2_fixed() << std::endl;

    if (n <= 1000)
    {
        std::cout << sub1();
    }
    else
    {
        std::cout << sub2();
    }

    return 0;
}
