#include <bits/stdc++.h>
#define task "rect"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e6;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

int m, n;
int a[maxn + 7];
int s[maxn + 7], t[maxn + 7], poss, post, h, ans;

void solve()
{
    std::stack<int> st;
    for (int i = 1; i <= n; i++)
    {
        while (!st.empty() && a[st.top()] >= a[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            s[i] = 0;
        }
        else
        {
            s[i] = st.top();
        }
        st.push(i);
    }

    while (!st.empty())
    {
        st.pop();
    }

    for (int i = n; i >= 1; i--)
    {
        while (!st.empty() && a[st.top()] >= a[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            t[i] = n + 1;
        }
        else
        {
            t[i] = st.top();
        }
        st.push(i);

        if ((t[i] - s[i] - 1) * a[i] > ans)
        {
            ans = (t[i] - s[i] - 1) * a[i];
            poss = s[i];
            post = t[i];
            h = a[i];
        }
    }
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

    std::cin >> m >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }

    solve();
    int res = ans;

    for (int i = 1; i <= n; i++)
    {
        a[i] = m - a[i];
    }

    solve();

    if (res >= ans)
    {
        std::cout << res << "\n";
        std::cout << 1 << " " << poss + 1 << "\n";
        std::cout << h << " " << post - 1;
    }
    else
    {
        std::cout << ans << "\n";
        std::cout << m - h + 1 << " " << poss + 1 << "\n";
        std::cout << m << " " << post - 1;
    }

    return 0;
}
