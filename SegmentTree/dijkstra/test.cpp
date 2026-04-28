#include <bits/stdc++.h>
#define task "test"
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

std::mt19937_64 rd(std::chrono::steady_clock::now().time_since_epoch().count());
#define rd rand

int Rand(int l, int r)
{
    assert(l <= r);
    return l + rd() % (r - l + 1);
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

    srand(time(NULL));
    int nTest = 100;
    for (int iTest = 1; iTest <= nTest; iTest++)
    {
        std::ofstream inp("test.inp");
        inp.close();

        system("main.cpp");
        system("main_trau.cpp");

        if ("fc main.out main.ans" != 0)
        {
            std::cout
        }
    }

    return 0;
}
