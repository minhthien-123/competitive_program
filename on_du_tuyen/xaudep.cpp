#include <bits/stdc++.h>
#define task "xaudep"
#define _Thiendeptrai_ signed main()
#define ll long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 200;

bool check(char c)
{
    return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

std::string s;
int a[maxn + 7];
int n;
ll dp[maxn + 7][5][2][2];

ll solve(int pos, int len, bool v, bool l);

void count(int pos, int len, bool v, bool l, bool V, bool L, ll cnt)
{
    int nv = V;

    int nlen;
    if (len == 0)
    {
        nlen = 1;
    }
    else
    {
        if (nv == v)
        {
            nlen = len + 1;
        }
        else
        {
            nlen = 1;
        }
    }

    if (nlen > 2)
    {
        return;
    }

    int nl = L;
    nl = nl | (l ? 1 : 0);

    ll sub = solve(pos + 1, nlen, nv, nl);
    if (sub == 0)
    {
        return;
    }
    dp[pos][len][v][l] += cnt * sub;
}

ll solve(int pos, int len, bool v, bool l)
{
    if (pos > n)
    {
        return l;
    }
    ll &memo = dp[pos][len][v][l];
    if (memo != -1)
    {
        return memo;
    }
    memo = 0;
    int type = a[pos];
    if (type == -1)
    {
        count(pos, len, v, l, true, false, 5LL);
        count(pos, len, v, l, false, true, 1LL);
        count(pos, len, v, l, false, false, 20LL);
    }
    else if (type == 0)
    {
        count(pos, len, v, l, true, false, 1LL);
    }
    else if (type == 1)
    {
        count(pos, len, v, l, false, true, 1LL);
    }
    else
    {
        count(pos, len, v, l, false, false, 1LL);
    }
    return memo;
}

_Thiendeptrai_
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    if (std::fopen(task ".inp", "r"))
    {
        std::freopen(task ".inp", "r", stdin);
        std::freopen(task ".out", "w", stdout);
    }

    std::cin >> s;
    n = s.size();
    s = " " + s;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '?')
            a[i] = -1;
        else if (check(s[i]))
            a[i] = 0;
        else if (s[i] == 'L')
            a[i] = 1;
        else
            a[i] = 2;
    }

    memset(dp, -1, sizeof dp);

    ll ans = solve(1, 0, 0, 0);
    std::cout << ans << "\n";

    return 0;
}
