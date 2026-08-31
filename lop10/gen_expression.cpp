#include <bits/stdc++.h>
#define int long long
const std::string task = "expression";
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
        int n = Rand(1, 100);
        int s = 0;
        int a[n + 7];
        for (int i = 1; i <= n; i++)
        {
            a[i] = Rand(1, 100);
            if (i == 1)
            {
                s = a[i];
                continue;
            }
            int query = Rand(1, 2);
            if (query == 1)
            {
                s += a[i];
            }
            else
            {
                s -= a[i];
            }
        }
        inp << n << " " << s << "\n";
        for (int i = 1; i <= n; i++)
        {
            inp << a[i] << " ";
        }
        inp.close();
        auto start = std::chrono::system_clock::now();
        system((task + ".exe").c_str());
        auto end = std::chrono::system_clock::now();
        int time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        system(("checker_" + task + ".exe").c_str());
        std::ifstream check((task + ".chk").c_str());
        std::string result;
        check >> result;
        if (result == "ACCEPTED")
            std::cout << "TEST " << iTest << ": " << result << " " << time << "ms\n";
        else
        {
            std::cout << "TEST " << iTest << ": " << result << "\n";
            return 0;
        }

        /*system((task + "_trau.exe").c_str());
        if (system(("fc " + task + ".out " + task + "_trau.out").c_str()) != 0)
        {
            std::cout << "TEST " << iTest << ": WRONG ANSWER!\n";
            return 0;
        }
        std::cout << "TEST " << iTest << ": ACCEPTED!\n";*/
    }

    return 0;
}