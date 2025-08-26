#include <bits/stdc++.h>
#define task "table"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e2;
const int inf = 1e18;
const int mod1 = 1e9 + 3;
const int mod2 = 1e9 + 7;
const int base1 = 31;
const int base2 = 131;

int n;
std::string s;
int a[maxn + 7];
int p2[maxn + 7], p1[maxn + 7];

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
    std::cin >> s;

    for (int i = 1; i <= n; i++)
    {
        p1[i] = (p1[i - 1] * base1) % mod1;
        p2[i] = (p2[i - 1] * base2) % mod2;
    }

    int h1 = 0, h2 = 0;
    for (char c : s)
    {
        int v = c - '0' + 1;
        h1 = (h1 * base1 + v) % mod1;
        h2 = (h2 * base2 + v) % mod2;
    }

    int lim = 1e15;
    std::deque<char> dq;
    int H1, H2;
    int pos = 0;

    

    return 0;
}
