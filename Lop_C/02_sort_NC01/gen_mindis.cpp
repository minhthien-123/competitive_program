#include <bits/stdc++.h>
#define int long long
const int test = 100;

std::mt19937_64 rd(std::chrono::steady_clock::now().time_since_epoch().now());
#define rd rand

int Rand(int l, int r)
{
    assert(l <= r);
    return l + rd() % (r - l + 1);
}

signed main()
{
    srand(time(NULL));
    for (int z = 1; z <= test; z++)
    {
        std::ofstream inp("mindis.inp");
    }
}