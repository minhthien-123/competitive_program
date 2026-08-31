#include <bits/stdc++.h>
#define task "rooms"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e6 + 7;

struct rooms{
    int val, type, dex;
};

rooms a[maxn];
int n, beg, en, m, meet[maxn], i, j, tmp;
std::vector<int> res[maxn];
std::stack<int>  st;

bool cmp(rooms x, rooms y)
{
    if (x.val == y.val) return x.type > y.type;
    else return x.val < y.val;
}

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
    for (i = 1; i <= n; i++)
    {
        std::cin >> beg >> en;
        a[i * 2 - 1].val   = beg;
        a[i * 2].type      = 0;
        a[i * 2 - 1].dex   = i;

        a[i * 2].val  = en;
        a[i * 2].type = 1;
        a[i * 2].dex  = i;
    }

    for (i = n; i >= 1; i--)
    {
        st.push(i);
    }

    std::sort(a + 1, a + 2 * n + 1, cmp);

    for (i = 1; i <= 2 * n; i++)
    {
        if (a[i].type == 0)
        {
            tmp = st.top();
            st.pop();
            meet[a[i].dex] = tmp;

            res[tmp].push_back(a[i].dex);
            m = std::max(m, tmp);
        }
        else
        {
            st.push(meet[a[i].dex]);
        }
    }

    std::cout << m << "\n";
    for (i = 1; i <= m; i++)
    {
        for (j = 0;j < res[i].size(); j++)
        {
            std::cout << res[i][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
