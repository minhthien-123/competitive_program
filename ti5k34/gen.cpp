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

const int maxn = 1e5;
int n;
int a[maxn + 7];

signed main()
{
    srand(time(NULL));
    for (int iTest = 1; iTest <= test; iTest++)
    {
        std::ofstream inp("main.inp");
        /*int n = Rand(1, 1000);
        for (int i = 1; i <= n; i++)
        {
            int x;
            x = Rand(1, 1000);
            inp << x << " ";
        }*/
        inp.close();
        system("main.exe");
        system("main_trau.exe");
        if (system("fc main.out main.out") != 0)
        {
            std::cout << "TEST " << iTest << ": WRONG ANSWER!\n";
            return 0;
        }
        std::cout << "TEST " << iTest << ": ACCEPTED!\n";
    }

    return 0;
}