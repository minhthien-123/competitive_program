#include <bits/stdc++.h>
#include "abkm.h"
using namespace std;

namespace personA
{
    vector<int> A2B(vector<int> _A, int _K)
    {
        vector<int> res;
        if (_K == 1)
        {
            int sa = 0;
            for (int i : _A)
            {
                sa += i;
                sa %= 101;
            }

            if (sa == 0)
            {
                sa = 101;
            }
            res.push_back(sa);
        }
        else if (_K == 2)
        {
            int sa = 0, pa = 1;
            for (int i : _A)
            {
                sa += i;
                sa %= 101;
                pa *= i;
                pa %= 101;
            }

            if (sa == 0)
            {
                sa = 101;
            }
            if (pa == 0)
            {
                pa = 101;
            }

            res.push_back(sa);
            res.push_back(pa);
        }
        else if (_K == 3)
        {
            int s1 = 0, s2 = 0, s3 = 0;
            for (int i : _A)
            {
                int p1 = i % 101;
                int p2 = (p1 * i) % 101;
                int p3 = (p2 * i) % 101;
                s1 = (s1 + p1) % 101;
                s2 = (s2 + p2) % 101;
                s3 = (s3 + p3) % 101;
            }
            if (s1 == 0)
                s1 = 101;
            if (s2 == 0)
                s2 = 101;
            if (s3 == 0)
                s3 = 101;
            res.push_back(s1);
            res.push_back(s2);
            res.push_back(s3);
        }
        else if (_K == 4)
        {
            int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
            for (int i : _A)
            {
                int p1 = i % 101;
                int p2 = (p1 * i) % 101;
                int p3 = (p2 * i) % 101;
                int p4 = (p3 * i) % 101;
                s1 = (s1 + p1) % 101;
                s2 = (s2 + p2) % 101;
                s3 = (s3 + p3) % 101;
                s4 = (s4 + p4) % 101;
            }
            if (s1 == 0)
                s1 = 101;
            if (s2 == 0)
                s2 = 101;
            if (s3 == 0)
                s3 = 101;
            if (s4 == 0)
                s4 = 101;
            res.push_back(s1);
            res.push_back(s2);
            res.push_back(s3);
            res.push_back(s4);
        }
        else if (_K == 5)
        {
            int s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0;
            for (int i : _A)
            {
                int p1 = i % 101;
                int p2 = (p1 * i) % 101;
                int p3 = (p2 * i) % 101;
                int p4 = (p3 * i) % 101;
                int p5 = (p4 * i) % 101;
                s1 = (s1 + p1) % 101;
                s2 = (s2 + p2) % 101;
                s3 = (s3 + p3) % 101;
                s4 = (s4 + p4) % 101;
                s5 = (s5 + p5) % 101;
            }
            if (s1 == 0)
                s1 = 101;
            if (s2 == 0)
                s2 = 101;
            if (s3 == 0)
                s3 = 101;
            if (s4 == 0)
                s4 = 101;
            if (s5 == 0)
                s5 = 101;
            res.push_back(s1);
            res.push_back(s2);
            res.push_back(s3);
            res.push_back(s4);
            res.push_back(s5);
        }
        return res;
    }
}

namespace personB
{
    vector<int> Btell(vector<int> _B, vector<int> _P)
    {
        vector<int> res;

        int pw[105][6];
        for (int i = 1; i <= 100; i++)
        {
            pw[i][1] = i % 101;
            pw[i][2] = (pw[i][1] * i) % 101;
            pw[i][3] = (pw[i][2] * i) % 101;
            pw[i][4] = (pw[i][3] * i) % 101;
            pw[i][5] = (pw[i][4] * i) % 101;
        }

        if (_P.size() == 1)
        {
            int sa = _P[0] % 101;
            int sb = 0;

            for (int i : _B)
            {
                sb += i;
                sb %= 101;
            }

            int S = (sa + sb) % 101;
            int ans = (101 - S) % 101;

            res.push_back(ans);
        }
        else if (_P.size() == 2)
        {
            int sa = _P[0] % 101, sb = 0;
            int pa = _P[1] % 101, pb = 1;

            for (int i : _B)
            {
                sb += i;
                sb %= 101;
                pb *= i;
                pb %= 101;
            }

            int S = (101 - (sa + sb) % 101) % 101;

            for (int a = 1; a <= 100; a++)
            {
                int b = (S - a + 101) % 101;

                if (b == 0 || a >= b)
                {
                    continue;
                }
                int P = (a * b) % 101;
                P = (P * pa) % 101;
                P = (P * pb) % 101;

                if (P == 100)
                {
                    res.push_back(a);
                    res.push_back(b);
                    break;
                }
            }
        }
        else if (_P.size() == 3)
        {
            int sa1 = _P[0] % 101, sa2 = _P[1] % 101, sa3 = _P[2] % 101;
            int sb1 = 0, sb2 = 0, sb3 = 0;
            for (int i : _B)
            {
                sb1 = (sb1 + pw[i][1]) % 101;
                sb2 = (sb2 + pw[i][2]) % 101;
                sb3 = (sb3 + pw[i][3]) % 101;
            }
            int r1 = (101 - (sa1 + sb1) % 101) % 101;
            int r2 = (101 - (sa2 + sb2) % 101) % 101;
            int r3 = (101 - (sa3 + sb3) % 101) % 101;

            for (int a = 1; a <= 98; a++)
            {
                for (int b = a + 1; b <= 99; b++)
                {
                    int c = ((r1 - a - b) % 101 + 101) % 101;
                    if (c <= b || c > 100)
                        continue;

                    if ((pw[a][2] + pw[b][2] + pw[c][2]) % 101 != r2)
                        continue;
                    if ((pw[a][3] + pw[b][3] + pw[c][3]) % 101 == r3)
                    {
                        res.push_back(a);
                        res.push_back(b);
                        res.push_back(c);
                        return res;
                    }
                }
            }
        }
        else if (_P.size() == 4)
        {
            int sa1 = _P[0] % 101, sa2 = _P[1] % 101, sa3 = _P[2] % 101, sa4 = _P[3] % 101;
            int sb1 = 0, sb2 = 0, sb3 = 0, sb4 = 0;
            for (int i : _B)
            {
                sb1 = (sb1 + pw[i][1]) % 101;
                sb2 = (sb2 + pw[i][2]) % 101;
                sb3 = (sb3 + pw[i][3]) % 101;
                sb4 = (sb4 + pw[i][4]) % 101;
            }
            int r1 = (101 - (sa1 + sb1) % 101) % 101;
            int r2 = (101 - (sa2 + sb2) % 101) % 101;
            int r3 = (101 - (sa3 + sb3) % 101) % 101;
            int r4 = (101 - (sa4 + sb4) % 101) % 101;

            for (int a = 1; a <= 97; a++)
            {
                for (int b = a + 1; b <= 98; b++)
                {
                    for (int c = b + 1; c <= 99; c++)
                    {
                        int d = ((r1 - a - b - c) % 101 + 101) % 101;
                        if (d <= c || d > 100)
                            continue;

                        if ((pw[a][2] + pw[b][2] + pw[c][2] + pw[d][2]) % 101 != r2)
                            continue;
                        if ((pw[a][3] + pw[b][3] + pw[c][3] + pw[d][3]) % 101 != r3)
                            continue;
                        if ((pw[a][4] + pw[b][4] + pw[c][4] + pw[d][4]) % 101 == r4)
                        {
                            res.push_back(a);
                            res.push_back(b);
                            res.push_back(c);
                            res.push_back(d);
                            return res;
                        }
                    }
                }
            }
        }
        else if (_P.size() == 5)
        {
            int sa1 = _P[0] % 101, sa2 = _P[1] % 101, sa3 = _P[2] % 101, sa4 = _P[3] % 101, sa5 = _P[4] % 101;
            int sb1 = 0, sb2 = 0, sb3 = 0, sb4 = 0, sb5 = 0;
            for (int i : _B)
            {
                sb1 = (sb1 + pw[i][1]) % 101;
                sb2 = (sb2 + pw[i][2]) % 101;
                sb3 = (sb3 + pw[i][3]) % 101;
                sb4 = (sb4 + pw[i][4]) % 101;
                sb5 = (sb5 + pw[i][5]) % 101;
            }
            int r1 = (101 - (sa1 + sb1) % 101) % 101;
            int r2 = (101 - (sa2 + sb2) % 101) % 101;
            int r3 = (101 - (sa3 + sb3) % 101) % 101;
            int r4 = (101 - (sa4 + sb4) % 101) % 101;
            int r5 = (101 - (sa5 + sb5) % 101) % 101;

            for (int a = 1; a <= 96; a++)
            {
                for (int b = a + 1; b <= 97; b++)
                {
                    for (int c = b + 1; c <= 98; c++)
                    {
                        for (int d = c + 1; d <= 99; d++)
                        {
                            int e = ((r1 - a - b - c - d) % 101 + 101) % 101;
                            if (e <= d || e > 100)
                                continue;

                            if ((pw[a][2] + pw[b][2] + pw[c][2] + pw[d][2] + pw[e][2]) % 101 != r2)
                                continue;
                            if ((pw[a][3] + pw[b][3] + pw[c][3] + pw[d][3] + pw[e][3]) % 101 != r3)
                                continue;
                            if ((pw[a][4] + pw[b][4] + pw[c][4] + pw[d][4] + pw[e][4]) % 101 != r4)
                                continue;
                            if ((pw[a][5] + pw[b][5] + pw[c][5] + pw[d][5] + pw[e][5]) % 101 == r5)
                            {
                                res.push_back(a);
                                res.push_back(b);
                                res.push_back(c);
                                res.push_back(d);
                                res.push_back(e);
                                return res;
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
}