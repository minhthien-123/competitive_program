#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <filesystem>
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include <algorithm>

using namespace std;
namespace fs = std::filesystem;

mt19937_64 rng(random_device{}());

long long rand_int(long long l, long long r)
{
    return uniform_int_distribution<long long>(l, r)(rng);
}

int main()
{
    if (system("g++ -O3 self.cpp -o self_exec") != 0)
    {
        return 1;
    }

    int test_count = 0;
    for (int i = 1; test_count < 20; ++i)
    {
        if (i == 19 || i == 20 || i == 39 || i == 40)
        {
            continue;
        }

        test_count++;

        stringstream ss;
        ss << "Test" << setfill('0') << setw(2) << i;
        string folder_name = ss.str();

        fs::create_directory(folder_name);

        string inp_file = folder_name + "/SELF.INP";
        string out_file = folder_name + "/SELF.OUT";

        ofstream fout(inp_file);

        int n, q;
        if (i <= 12)
        {
            n = rand_int(3, 1000);
            q = rand_int(1, 1000);
        }
        else
        {
            n = rand_int(1000, 1000000);
            q = rand_int(1000, 1000000);
        }

        fout << n << " " << q << "\n";

        vector<long long> a(n + 1);

        if (i == 1)
        {
            long long val = rand_int(1, 1000000000);
            for (int j = 1; j <= n; ++j)
                a[j] = val;
        }
        else if (i >= 2 && i <= 5)
        {
            for (int j = 1; j <= n; ++j)
                a[j] = rand_int(1, 1000000000);
            if (i == 2)
            {
                sort(a.begin() + 1, a.end());
            }
            else if (i == 3)
            {
                sort(a.begin() + 1, a.end(), greater<long long>());
            }
            else if (i == 4)
            {
                int mid = n / 2;
                sort(a.begin() + 1, a.begin() + mid + 1, greater<long long>());
                sort(a.begin() + mid + 1, a.end());
            }
            else if (i == 5)
            {
                int mid = n / 2;
                sort(a.begin() + 1, a.begin() + mid + 1);
                sort(a.begin() + mid + 1, a.end(), greater<long long>());
            }
        }
        else
        {
            for (int j = 1; j <= n; ++j)
            {
                a[j] = rand_int(1, 1000000000);
            }
        }

        for (int j = 1; j <= n; ++j)
        {
            fout << a[j] << (j == n ? "" : " ");
        }
        fout << "\n";

        for (int j = 1; j <= q; ++j)
        {
            int L = rand_int(1, n - 1);
            int R = rand_int(L + 1, n);
            fout << L << " " << R << "\n";
        }
        fout.close();

        string cmd = "./self_exec < " + inp_file + " > " + out_file;
        system(cmd.c_str());
    }

    system("rm self_exec");

    return 0;
}