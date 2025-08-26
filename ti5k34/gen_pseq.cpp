#include <bits/stdc++.h>
#define int long long
const std::string task = "pseq";
const int test = 100;

std::mt19937_64 rd(std::chrono::steady_clock::now().time_since_epoch().count());
#define rd rand

int Rand(int l, int r)
{
    assert(l <= r);
    return l + rd() % (r - l + 1);
}

signed main()
{
    srand(time(NULL));
    for (int iTest = 1; iTest <= test; iTest++)
    {
        std::ofstream inp((task + ".inp").c_str());
        int n = Rand(1, 10000);
        inp << n;
        inp.close();
        system((task + ".exe").c_str());
        system(("checker_" + task + ".exe").c_str());
    }

    return 0;
}