#include <bits/stdc++.h>
const std::string task = "sp01";
const int test = 3;

std::mt19937_64 rd(std::chrono::steady_clock::now().time_since_epoch().count());
#define rand rd
#define int long long

int Rand(int l, int r)
{
    assert (l <= r);
    return l + rd() % (r - l + 1);
}

int n;
std::string s;

signed main()
{
    srand(time(NULL));
    for (int i = 1; i <= test; i++)
    {
        std::ofstream inp((task + ".inp").c_str());
        n = Rand(1, 10);
        s = "";
        for (int i = 1; i <= n; i++)
        {
            int tmp = Rand(0, 1);
            s = s + (tmp + "0");
        }
        std::cout << s << "\n";
        inp << s;
        inp.close();
        system("trungthai.exe");
        system("lbracket.exe");
        if (system("fc sp01.out sp01.ans") != 0)
        {
            std::cout << "Test " << i << ": WA\n";
        }

        std::cout << "Test " << i << "AC\n";
    }

    return 0;
}
