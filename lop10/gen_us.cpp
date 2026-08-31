#include <bits/stdc++.h>
const std::string task = "us";
const int test = 100;
const int maxn = 1e3;

std::mt19937_64 rd(std::chrono::steady_clock::now().time_since_epoch().count());
#define rand rd

int Rand(int l, int r)
{
    assert(l <= r);
    return l + rd() % (r - l + 1);
}

int t;
int a, b;

signed main()
{
    srand(time(NULL));
    for (int i = 1; i <= test; i++)
    {
        std::ofstream inp((task + ".inp").c_str());
        t = Rand(1, 10);
        inp << t << "\n";
        for (int i = 1; i <= t; i++)
        {
            a = Rand(1, 1000);
            b = Rand(a, 1000);
            inp << a << " " << b << "\n";
        }
        inp.close();
        system((task + ".exe").c_str());
        system((task + "_trau.exe").c_str());
        if (system("fc us.out us.ans") != 0)
        {
            std::cout << i << ": WA\n";
            return 0;
        }
        std::cout << i << ": AC\n";
    }
}
