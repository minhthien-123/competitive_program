#include <bits/stdc++.h>
#define task "bt1"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e3;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;

int n;

std::string operator*(std::string a, int b)
{
    if (a == "0" && b == 0)
    {
        return "0";
    }
    int n = a.size();
    std::string c(n, '0');
    int tmp = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        tmp += (a[i] - '0') * b;
        c[i] = tmp % 10 + '0';
        tmp /= 10;
    }
    if (tmp > 0)
    {
        c = std::to_string(tmp) + c;
    }
    return c;
}

std::string solve(int n)
{
    std::vector<int> t;
    for (int i = n + 2; i <= 2 * n; i++)
    {
        t.pb(i);
    }

    for (int i = 2; i <= n; i++)
    {
        int tmp = i;
        for (int j = 0; j < t.size() && tmp > 0; j++)
        {
            int d = std::__gcd(t[j], tmp);
            tmp /= d;
            t[j] /= d;
        }
    }
    std::string res = "1";
    for (int i = 0; i < t.size(); i++)
    {
        res = res * t[i];
    }
    return res;
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

    while (std::cin >> n)
    {
        n /= 2;
        std::string res = solve(n);
        if (res.size() < 10)
        {
            std::cout << res << "\n";
        }
        else
        {
            std::cout << res.substr(0, 5) << "..." << res.substr(res.size() - 5, 5) << "\n";
        }
    }

    return 0;
}
