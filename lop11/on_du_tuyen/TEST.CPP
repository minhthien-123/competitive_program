#include <bits/stdc++.h>
#define task "hehe"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;

int n;
int h[maxn + 7], w[maxn + 7];
std::stack<std::pair<int, int>> st;

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> h[i];
    }
    for (int i = 1; i <= n; i++)
    {
        std::cin >> w[i];
    }

    h[n + 1] = 0;
    w[n + 1] = 0;
    n++;

    std::stack<std::pair<int, int>> st;
    st.push({0, 0});

    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        int W = 0;
        while (st.top().fi > h[i])
        {
            ii tmp = st.top();
            W = (W + tmp.se) % mod;
            st.pop();

            int H = std::max(h[i], st.top().fi);
            int d = tmp.fi - H;

            int x = (d * (d + 1) % mod * inv % mod + d * H % mod) % mod;
            int y = (W * (W + 1) % mod * inv % mod) % mod;
            ans = (ans + x * y % mod) % mod;
        }

        if (st.top().fi == h[i])
        {
            st.top().se = (st.top().se + W + w[i]) % mod;
        }
        else
        {
            st.push({h[i], (W + w[i]) % mod});
        }
    }

    std::cout << ans % mod;

    return 0;
}
