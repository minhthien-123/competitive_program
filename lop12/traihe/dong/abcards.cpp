#include <bits/stdc++.h>
#include "abcards.h"

long long c[60][60];

void init()
{
    for (int i = 0; i <= 52; i++)
    {
        c[i][0] = 1;
        for (int k = 1; k <= i; k++)
        {
            c[i][k] = c[i - 1][k - 1] + c[i - 1][k];
        }
    }
}

namespace personA
{
    long long A2B(vector<int> _C)
    {
        init();
        int k = _C.size();

        long long dem = 0;
        for (int i = 10; i < k; i++)
        {
            dem += c[52][i];
        }

        vector<int> cards = _C;
        sort(cards.begin(), cards.end());

        long long rank = 0;
        int last = 0;
        for (int i = 0; i < k; i++)
        {
            for (int x = last + 1; x < cards[i]; x++)
            {
                rank += c[52 - x][k - 1 - i];
            }
            last = cards[i];
        }

        return dem + rank;
    }
}

namespace personB
{
    vector<int> Btell(long long _Num)
    {
        init();

        long long rank = _Num;
        int k = 10;

        while (k <= 20 && rank >= c[52][k])
        {
            rank -= c[52][k];
            k++;
        }

        vector<int> P;
        int last = 0;
        for (int i = 0; i < k; i++)
        {
            for (int x = last + 1; x <= 52; x++)
            {
                long long cnt = c[52 - x][k - 1 - i];
                if (rank >= cnt)
                {
                    rank -= cnt;
                }
                else
                {
                    P.push_back(x);
                    last = x;
                    break;
                }
            }
        }
        return P;
    }
}