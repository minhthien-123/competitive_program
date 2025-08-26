#include <bits/stdc++.h>
#define task "frogs"
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

int n;
int a[maxn + 7], f[maxn + 7];
int ans[maxn + 7], st[maxn + 7];
int top;

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
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        std::cin >> f[i];
    }

    st[0] = inf;

    for (int i = n - 1; i >= 0; i--)
    {
        while (st[top] <= a[i])
        {
            top--;
        }
        st[++top] = a[i];
        if (top <= f[i])
        {
            ans[i] = -1;
        }
        else
        {
            ans[i] = st[top - f[i]];
        }
    }

    for (int i = 0; i < n; i++)
    {
        std::cout << ans[i] << " ";
    }

    return 0;
}
