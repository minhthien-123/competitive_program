#include <bits/stdc++.h>
#define task "lm"
#define int long long

const int maxn = 1e6 + 207;

int n;
bool check[maxn];
std::string m;

bool Check(int n)
{
    std::string s = std::to_string(n);
    for (int i = 0; i < s.size(); i++)
        if (!check[s[i] - '0'])
            return false;
    return true;
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    //std::freopen(task ".inp", "r", stdin);
    //std::freopen(task ".out", "w", stdout);

    std::cin >> n >> m;
    for (int i = 0; i < m.size(); i++)
        check[m[i] - '0'] = true;
    for (int i = 1; i <= 10000000; i++)
        if (Check(n * i))
        {
            std::cout << n * i;
            return 0;
        }
    std::cout << 0;

    return 0;
}
