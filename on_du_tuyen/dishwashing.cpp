#include <bits/stdc++.h>
#define task "dishes"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = mod / 2;

int n;
int a[maxn + 7];
std::vector<std::stack<int>> vs;
std::stack<int> st;
std::vector<int> v;

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task ".in", "r"))
    {
        std::freopen(task ".in", "r", stdin);
        std::freopen(task ".out", "w", stdout);
    }

    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }

    for (int i = 1; i <= n; i++)
    {
        if (!st.empty() && st.top() > a[i])
        {
            std::cout << i - 1;
            exit(0);
        }

        int pos = std::lower_bound(v.begin(), v.end(), a[i]) - v.begin();

        if (pos == v.size())
        {
            std::stack<int> s;
            s.push(a[i]);
            vs.push_back(s);
            v.push_back(a[i]);
        }
        else
        {
            while (!vs[pos].empty() && vs[pos].top() < a[i])
            {
                st.push(vs[pos].top());
                vs[pos].pop();
            }
            vs[pos].push(a[i]);
        }
    }

    std::cout << n;
    return 0;
}