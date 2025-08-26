#include <bits/stdc++.h>
#define task "select"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 5e3;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;

int n, m;
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

    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }

    std::sort(a + 1, a + n + 1);

    int tmp = 0, cnt = 0, id = 1;

    std::stack<int> st;

    while (tmp < m)
    {
        while (id <= n && a[id] <= tmp + 1)
        {
            st.push(a[id]);
            id++;
        }
        if (!st.size())
        {
            std::cout << 0;
            return 0;
        }

        tmp += st.top();
        st.pop();
        cnt++;
    }

    std::cout << cnt;

    return 0;
}
