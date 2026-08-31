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
        std::ofstream inp("gcdseq.inp");
        int n = Rand(1, 100), q = Rand(1, 100), k = Rand(1, 1000);
        inp << n << " " << q << " " << k << "\n";
        for (int i = 1; i <= n; i++)
        {
            int x;
            x = Rand(1, 1000);
            inp << x << " ";
        }
        for (int i = 1; i <= q; i++)
        {
            int l, r;
            l = 1;
            r = Rand(l, n);
            inp << l << " " << r << "\n";
        }
        inp.close();
        system("gcdseq.exe");
        system("gcdseq_trau.exe");
        if (system("fc gcdseq.out gcdseq.ans") != 0)
        {
            std::cout << "TEST " << iTest << ": WRONG ANSWER!\n";
            return 0;
        }
        std::cout << "TEST " << iTest << ": ACCEPTED!\n";
    }

    return 0;
}