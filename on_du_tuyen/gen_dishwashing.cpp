#include <bits/stdc++.h>
#define int long long
const std::string task = "main";
const int test = 1;

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
        inp << n << "\n";
        std::vector<int> v;
        for (int i = 1; i <= n; i++)
        {
            v.push_back(i);
        }
        std::random_shuffle(v.begin(), v.end());
        for (int i = 0; i < n; i++)
        {
            inp << v[i] << " ";
        }
        inp.close();
        auto start = std::chrono::system_clock::now();
        system((task + ".exe").c_str());
        auto end = std::chrono::system_clock::now();
        int time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        //system((task + "_trau.exe").c_str());
        /*if (system(("fc " + task + ".out " + task + "_trau.out").c_str()) != 0)
        {
            std::cout << "TEST " << iTest << ": WRONG ANSWER!\n";
            return 0;
        }
        std::cout << "TEST " << iTest << ": ACCEPTED!\n";*/
    }

    return 0;
}