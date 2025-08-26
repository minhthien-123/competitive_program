#include <bits/stdc++.h>
#define task "main"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 2 << 20;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;

int n, k;

std::vector<int> v;

void gen(int i, int res, bool flag)
{
    if (i == n)
    {
        v.pb(res);
        return;
    }

    if (!flag)
    {
        gen(i + 1, res << 1, 0);
        gen(i + 1, (res << 1) | 1, 1);
    }
    else
    {
        gen(i + 1, (res << 1) | 1, 0);
        gen(i + 1, res << 1, 1);
    }
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

    std::cin >> n >> k;
    gen(0, 0, 0);

    int pos = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == k)
        {
            pos = i;
            break;
        }
    }

    for (int i = pos + 1; i < v.size(); i++)
    {
        std::cout << v[i] << "\n";
    }
    for (int i = 0; i < pos; i++)
    {
        std::cout << v[i] << "\n";
    }

    return 0;
}

// 2
// 00
// 01
// 10
// 11