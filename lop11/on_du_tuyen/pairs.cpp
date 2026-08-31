#include <bits/stdc++.h>
#define task "pairs"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 5e5;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

int n, ans, a[maxn + 7];
std::stack<int> st;

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

    for (int i = 1; i <= n; i++)
    {
        while (!st.empty() && a[st.top()] < a[i])
        {
            ans++;
            st.pop();
        }
        if (!st.empty())
        {
            ans++;
            if (a[i] == a[st.top()])
            {
                continue;
            }
        }
        st.push(i);
    }

    std::cout << ans;

    return 0;
}
