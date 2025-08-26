#include <bits/stdc++.h>
#define int long long
const std::string task = "nqueens";
const int test = 80;

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
        int n = iTest;
        inp << n << '\n';
        inp.close();
        auto start = std::chrono::system_clock::now();
        system((task + ".exe").c_str());
        auto end = std::chrono::system_clock::now();
        int time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        system(("checker_" + task + ".exe").c_str());
        std::ifstream check((task + ".chk").c_str());
        std::string ans;
        check >> ans;
        std::cout << ans << " ";
        check.close();
        if (ans != "ACCEPTED")
        {
            std::cout << "Test " << iTest << ": WRONG ANSWER!\n";
            //return 0;
        }
        else
        {
            if (time > 1000)
            {
                std::cout << "Test " << iTest << ": TIME LIMIT EXCEED! (" << time << "ms)\n";
            }
            else
            {
                std::cout << "Test " << iTest << ": ACCEPTED!\n";
            }
        }
    }

    return 0;
}