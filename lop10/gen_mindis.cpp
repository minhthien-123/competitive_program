#include <bits/stdc++.h>
#define int long long
const int test = 100;

std::mt19937_64 rd(std::chrono::steady_clock::now().time_since_epoch().count());
#define rd rand

int Rand(int l, int r)
{
    assert(l <= r);
    return l + rd() % (r - l + 1);
}

int n, q;

signed main()
{
    srand(time(NULL));
    for (int z = 1; z <= test; z++)
    {
        std::ofstream inp("mindis.inp");
        n = Rand(1, 10);
        q = Rand(1, 100);
        inp << n << " " << q << "\n";
        for (int i = 1, x; i <= n; i++)
        {
            x = Rand(-1000000000, 1000000000);
            inp << x << " ";
        }
        inp << "\n";
        for (int i = 1, x; i <= q; i++)
        {
            x = Rand(-1000000000, 1000000000);
            inp << x << "\n";
        }

        inp.close();
        system("mindis.exe");
        system("mindis_trau.exe");
        if (system("fc mindis.ans mindis.out") != 0)
        {
            std::cout << z << ": WA\n";
            return 0;
        }
        std::cout << z << ": AC\n";
    }
}
