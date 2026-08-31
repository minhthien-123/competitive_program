#include <vector>
#include "abperm.h"
using namespace std;

namespace personA
{
    unsigned long long A2B(vector<int> _P)
    {
        int n = _P.size();
        unsigned long long fact[21];
        bool vis[25] = {false};

        fact[0] = 1;
        for (int i = 1; i <= 20; i++)
        {
            fact[i] = fact[i - 1] * i;
        }

        unsigned long long dem = 0;
        for (int i = 1; i < n; i++)
        {
            dem += fact[i];
        }

        unsigned long long cnt = 0;
        for (int i = 0; i < n; i++)
        {
            int used = 0;
            for (int j = 1; j < _P[i]; j++)
            {
                if (!vis[j])
                {
                    used++;
                }
            }
            cnt += used * fact[n - i - 1];
            vis[_P[i]] = true;
        }

        return cnt + dem;
    }
}

namespace personB
{
    vector<int> Btell(unsigned long long _Num)
    {
        std::vector<int> P;
        unsigned long long fact[21];
        bool vis[25] = {false};

        fact[0] = 1;
        for (int i = 1; i <= 20; i++)
        {
            fact[i] = fact[i - 1] * i;
        }

        int n = 1;
        unsigned long long dem = 0;
        while (n <= 20 && _Num >= dem + fact[n])
        {
            dem += fact[n];
            n++;
        }

        unsigned long long cnt = _Num - dem;

        for (int i = 0; i < n; i++)
        {
            unsigned long long count = cnt / fact[n - i - 1];
            cnt %= fact[n - i - 1];

            int used = 0;
            for (int j = 1; j <= n; j++)
            {
                if (!vis[j])
                {
                    if (used == count)
                    {
                        P.push_back(j);
                        vis[j] = true;
                        break;
                    }
                    used++;
                }
            }
        }

        return P;
    }
}