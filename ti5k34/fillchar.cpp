#include <bits/stdc++.h>
#define task "fillchar"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back

const int inf = 1e9 + 7;
const int maxn = 1e7;

int n, m, k, a[maxn + 7], par[maxn + 7], res[maxn + 7];
std::vector<iii> query;

void make_set(int n)
{
    for (int i = 1; i <= n; ++i)
    {
        par[i] = i;
    }
}

int find(int x)
{
    if (par[x] != x)
    {
        par[x] = find(par[x]);
    }
    return par[x];
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

    std::cin >> n >> m >> k;
    for (int i = 1; i <= m; ++i)
    {
        int l, r, c;
        std::cin >> l >> r >> c;
        query.pb({{l, r}, c});
    }

    for (int i = 1; i <= n; ++i)
    {
        res[i] = 1;
    }

    std::reverse(query.begin(), query.end());

    make_set(n + 1);

    for (int i = 0; i < query.size(); ++i)
    {
        int l = query[i].fi.fi;
        int r = query[i].fi.se;
        int c = query[i].se;
        int tmp = find(l);
        while (tmp <= r)
        {
            res[tmp] = c;
            par[tmp] = tmp + 1;
            tmp = find(tmp + 1);
        }
    }

    std::vector<int> v;
    for (int i = 1; i <= n; i++)
    {
        v.pb(res[i]);
    }

    std::stack<int> st;

    for (int i : v)
    {
        while (k && st.size() && st.top() < i)
        {
            st.pop();
            k--;
        }

        st.push(i);
    }

    while (k--)
    {
        st.pop();
    }

    std::vector<int> ans;

    while (st.size())
    {
        ans.pb(st.top());
        st.pop();
    }

    std::reverse(ans.begin(), ans.end());

    for (int i : ans)
    {
        std::cout << i;
    }

    return 0;
}
