#include <bits/stdc++.h>
#define task "palstr"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;

const int base = 31;

std::string s;
int n, k;

int p[maxn + 7], h1[maxn + 7], h2[maxn + 7];

int get(int l, int r, int h[])
{
    return (h[r] - h[l - 1] * p[r - l + 1] + mod * mod) % mod;
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
    std::cin >> s;
    std::cin >> k;

    p[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        p[i] = (p[i - 1] * base) % mod;
    }

    for (int i = 1; i <= n; i++)
    {
        h1[i] = (h1[i - 1] * base + s[i - 1] - 'a' + 1) % mod;
    }
    std::reverse(s.begin(), s.end());
    for (int i = 1; i <= n; i++)
    {
        h2[i] = (h2[i - 1] * base + s[i - 1] - 'a' + 1) % mod;
    }

    while (k--)
    {
        int l, r;
        std::cin >> l >> r;
        if (get(l, r, h1) == get(n - r + 1, n - l + 1, h2))
        {
            std::cout << "YES\n";
        }
        else
        {
            std::cout << "NO\n";
        }
    }

    return 0;
}
