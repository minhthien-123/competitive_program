#include <bits/stdc++.h>
#include "abperm.h"
const int n = 20;

unsigned long long dp[1 << 20][21];
int adj_mask[21];

void init()
{
    for (int i = 0; i <= n; i++)
    {
        adj_mask[i] = 0;
        for (int j = 1; j <= n; j++)
        {
            if (i == 0 || std::__gcd(i, j) == 1)
            {
                adj_mask[i] |= (1 << (j - 1));
            }
        }
    }

    for (int i = 0; i <= n; i++)
    {
        dp[0][i] = 1;
    }

    for (int mask = 1; mask < (1 << n); mask++)
    {
        for (int last = 0; last <= n; last++)
        {
            unsigned long long sum = 0;
            int avail = mask & adj_mask[last];

            while (avail > 0)
            {
                int bit = __builtin_ctz(avail);
                sum += dp[mask ^ (1 << bit)][bit + 1];
                avail &= avail - 1;
            }
            dp[mask][last] = sum;
        }
    }
}

namespace personA
{
    unsigned long long A2B(vector<int> _P)
    {
        init();
        int mask = (1 << n) - 1;
        int last = 0;
        unsigned long long rank = 0;

        for (int i = 0; i < n; i++)
        {
            int v = _P[i];
            for (int nxt = 1; nxt < v; nxt++)
            {
                if ((mask & (1 << (nxt - 1))) && (adj_mask[last] & (1 << (nxt - 1))))
                {
                    rank += dp[mask ^ (1 << (nxt - 1))][nxt];
                }
            }
            mask ^= (1 << (v - 1));
            last = v;
        }
        return rank;
    }
}

namespace personB
{
    vector<int> Btell(unsigned long long _Num)
    {
        init();
        vector<int> P(n);
        int mask = (1 << n) - 1;
        int last = 0;
        unsigned long long rank = _Num;

        for (int i = 0; i < n; i++)
        {
            for (int nxt = 1; nxt <= n; nxt++)
            {
                if ((mask & (1 << (nxt - 1))) && (adj_mask[last] & (1 << (nxt - 1))))
                {
                    unsigned long long cnt = dp[mask ^ (1 << (nxt - 1))][nxt];
                    if (rank >= cnt)
                    {
                        rank -= cnt;
                    }
                    else
                    {
                        P[i] = nxt;
                        mask ^= (1 << (nxt - 1));
                        last = nxt;
                        break;
                    }
                }
            }
        }
        return P;
    }
}