#include <bits/stdc++.h>
#define task ""
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e6 + 7;
int a[maxn], b[maxn];
std::string s1, s2;
std::string mn, mx;

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> s1 >> s2;
    for (int i = 0; i < s1.size(); i++)
    {
        a[i] = s1[i] - '0';
    }

    for (int i = 0; i < s2.size(); i++)
    {
        b[i] = s2[i] - '0';
    }

    int i = 0, j = 0;
    while (i < s1.size() && j < s2.size())
    {
        if (a[i] < b[j])
        {
            std::cout << a[i];
            i++;
        }
        else if (a[i] > b[j])
        {
            std::cout << b[j];
            j++;
        }
        else
        {
            if (a[i + 1] < b[j + 1])
            {
                std::cout << a[i];
                i++;
            }
            else if (a[i + 1] > b[j + 1])
            {
                std::cout << b[j];
                j++;
            }
            else
            {
                std::cout << a[i];
                i++;
            }
        }
    }

    while (i < s1.size())
    {
        std::cout << a[i];
        i++;
    }

    while (j < s2.size())
    {
        std::cout << b[j];
        j++;
    }

    std::cout << "\n";

    i = 0;
    j = 0;
    while (i < s1.size() && j < s2.size())
    {
        if (a[i] > b[j])
        {
            std::cout << a[i];
            i++;
        }
        else if (a[i] < b[j])
        {
            std::cout << b[j];
            j++;
        }
        else
        {
            if (a[i + 1] > b[j + 1])
            {
                std::cout << a[i];
                i++;
            }
            else if (a[i + 1] < b[j + 1])
            {
                std::cout << b[j];
                j++;
            }
            else
            {
                std::cout << a[i];
                i++;
            }
        }
    }

    while (i < s1.size())
    {
        std::cout << a[i];
        i++;
    }

    while (j < s2.size())
    {
        std::cout << b[j];
        j++;
    }

    return 0;
}
