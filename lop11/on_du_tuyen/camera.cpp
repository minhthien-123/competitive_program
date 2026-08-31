#include <bits/stdc++.h>
#define task "camera"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push
#define ins insert

const int maxn = 1e5;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;

int n;
int a[maxn + 7];
char s[maxn + 7];
std::stack<int> st;
int e[maxn + 7], w[maxn + 7];

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
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        std::cin >> s[i];
    }

    for (int i = 1; i <= n; i++)
    {
        w[i] = st.size();
        while (!st.empty() && a[st.top()] < a[i])
        {
            st.pop();
        }
        st.push(i);
    }

    while (st.size())
    {
        st.pop();
    }

    for (int i = n; i >= 1; i--)
    {
        e[i] = st.size();
        while (st.size() && a[st.top()] < a[i])
        {
            st.pop();
        }
        st.push(i);
    }

    for (int i = 1; i <= n; i++)
    {
        if (s[i] == 'E')
        {
            std::cout << e[i];
        }
        else
        {
            std::cout << w[i];
        }
        std::cout << " ";
    }

    return 0;
}
