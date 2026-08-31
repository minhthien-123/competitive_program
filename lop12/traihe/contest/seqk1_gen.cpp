#include <bits/stdc++.h>
#define int long long
const int test = 50;

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
        std::ofstream inp("seqk1.inp");
        int n = Rand(1, 20), q = Rand(1, n), k = Rand(1, 20);
        inp << n << " " << q << " " << k << "\n";
        inp.close();
        system("seqk1.exe");
        system("seqk1_trau.exe");
        if (system("fc seqk1.out seqk1.ans") != 0)
        {
            std::cout << "TEST " << iTest << ": WRONG ANSWER!\n";
            return 0;
        }
        std::cout << "TEST " << iTest << ": ACCEPTED!\n";
    }

    return 0;
}