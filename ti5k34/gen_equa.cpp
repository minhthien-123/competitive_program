#include <bits/stdc++.h>
#define int long long
const std::string task = "equa";
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
        int a, b, c, d, n, mod;
        a = Rand(0, 5);
        b = Rand(0, 5);
        c = Rand(0, 5);
        d = Rand(0, 5);
        n = Rand(1, 1000);
        mod = Rand(1, 1000000000);
        inp << a << " " << b << " " << c << " " << d << " " << n << " " << mod << "\n";
        inp.close();
        auto start = std::chrono::system_clock::now();
        system((task + ".exe").c_str());
        auto end = std::chrono::system_clock::now();
        int time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        //system((task + "_trau.exe").c_str());
        if (system(("fc " + task + ".out " + task + ".ans").c_str()) != 0)
        {
            std::cout << "TEST " << iTest << ": WRONG ANSWER!\n";
            return 0;
        }
        std::cout << "TEST " << iTest << ": ACCEPTED!\n";
    }

    return 0;
}