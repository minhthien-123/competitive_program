#include <bits/stdc++.h>
#define task "main"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e6;
const int inf  = 1e18;

int n;
int a[maxn + 7]; 

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

    std::stack<int> st;

    for (int i = 1; i <= n; i++)
    {
        while (!st.empty() && a[st.top()] >= a[i])
        {
            st.pop();
        }

        if (!st.empty())
        {
            std::cout << st.top() << " ";
        }
        else
        {
            std::cout << 0 << " ";
        }
        st.push(i);
    }

    return 0;
}
