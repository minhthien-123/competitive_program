#include <bits/stdc++.h>
#define task "cses1111"
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

std::string s, a;
int c = 0, r = 0, p[maxn * 2 + 7] = {0};

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

    std::cin >> s;

    for (char ch : s)
    {
        a += ' ';
        a += ch;
    }
    a = " " + a + " ";

    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        int j = 2 * c - i;
        if (i < r)
            p[i] = std::min(r - i, p[j]);
        while (i + p[i] + 1 < n && i - p[i] - 1 >= 0 && a[i + p[i] + 1] == a[i - p[i] - 1])
        {
            p[i]++;
        }
        if (i + p[i] > r)
        {
            r = i + p[i];
            c = i;
        }
    }

    int ans = 0, pos = 0;
    for (int i = 0; i < n; i++)
    {
        if (p[i] > ans)
        {
            ans = p[i];
            pos = i;
        }
    }

    int start = (pos - ans) / 2;
    std::cout << s.substr(start, ans);
    return 0;
}
