#include <bits/stdc++.h>
#define task "rect"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e6 + 7;

int m, n, i, beg[maxn], en[maxn], a[maxn], begin_ans, end_ans, ans = LLONG_MIN, height_ans, res;
std::stack<int> st;

void solve()
{
    std::stack<int> s;
    for (i = 1; i <= n; i++)
    {
        while (!s.empty() && a[s.top()] >= a[i])
            s.pop();
        if (s.empty())
            beg[i] = 0;
        else
            beg[i] = s.top();
        s.push(i);
    }

    while (!s.empty())
        s.pop();

    for (i = n; i >= 1; i--)
    {
        while (!s.empty() && a[s.top()] >= a[i])
            s.pop();
        if (s.empty())
            en[i] = n + 1;
        else
            en[i] = s.top();
        s.push(i);

        if ((en[i] - beg[i] - 1) * a[i] > ans)
        {
            ans = (en[i] - beg[i] - 1) * a[i];
            begin_ans = beg[i];
            end_ans = en[i];
            height_ans = a[i];
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
    for (i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }

    solve();
    res = ans;
    // std::cout << res << "\n";
    //  << begin_ans << " " << end_ans << " " << height_ans << "\n";

    for (i = 1; i <= n; i++)
    {
        a[i] = m - a[i];
    }

    solve();

    if (res >= ans)     
    {
        std::cout << res << "\n";
        std::cout << 1 << " " << begin_ans + 1 << "\n";
        std::cout << height_ans << " " << end_ans - 1;
    }
    else
    {
        std::cout << ans << "\n";
        std::cout << m - height_ans + 1 << " " << begin_ans + 1 << "\n";
        std::cout << m << " " << end_ans - 1;
        // std::cout << "\n";
    }

    // std::cout << 1 << " " << begin_ans + 2 << "\n";
    // std::cout << height_ans << " " << end_ans;
    // std::cout << begin_ans << " " << end_ans << " " << height_ans << "\n";
}

// 2 4 5 9 10 31 34 40
