#include <bits/stdc++.h>
#define task "cpack"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;

int n, q;
int a[maxn + 7], l[maxn + 7], r[maxn + 7], f[maxn + 7], pre[maxn + 7];
ii t[maxn + 7];

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

    std::cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }

    std::stack<int> st;
    for (int i = 1; i <= n; i++)
    {
        while (!st.empty() && a[st.top()] <= a[i])
        {
            st.pop();
        }

        if (st.empty())
        {
            l[i] = 0;
        }
        else
        {
            l[i] = st.top();
        }
        st.push(i);
    }

    while (!st.empty())
    {
        st.pop();
    }

    for (int i = n; i > 0; i--)
    {
        while (!st.empty() && a[st.top()] <= a[i])
        {
            st.pop();
        }

        if (st.empty())
        {
            r[i] = n + 1;
        }
        else
        {
            r[i] = st.top();
        }
        st.push(i);
    }

    for (int i = 1; i <= n; i++)
    {
        f[i] = r[i] - l[i] - 1;
    }
    for (int i = 1; i <= n; i++)
    {
        t[i] = {a[i], f[i]};
    }
    std::sort(t + 1, t + n + 1, [](const ii &x, const ii &y)
              { return x.fi < y.fi; });

    pre[1] = t[1].se;
    for (int i = 2; i <= n; i++)
    {
        pre[i] = std::max(pre[i - 1], t[i].se);
    }

    while (q--)
    {
        long long k;
        std::cin >> k;
        int ans = -1;
        int lo = 1, hi = n;
        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if (t[mid].fi <= k)
            {
                ans = mid;
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
        if (ans == -1)
        {
            std::cout << 0 << "\n";
        }
        else
        {
            std::cout << pre[ans] << "\n";
        }
    }
    return 0;
}
