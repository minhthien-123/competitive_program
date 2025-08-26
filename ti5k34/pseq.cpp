#include <bits/stdc++.h>
#define task "pseq"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e6;
const int mod = 1e9 + 7;
const int inf  = 1e18;

bool is_prime[maxn + 7];

void sieve()
{
    for (int i = 2; i <= maxn; i++)
    {
        is_prime[i] = true;
    }
    for (int i = 2; i * i <= maxn; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= maxn; j += i)
            {
                is_prime[j] = false;
            }
        }
    }
}

int n;
std::vector<int> a, b;

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> n;
    sieve();


    for (int i = 2 * n; i >= 2; i--)
    {
        if (i % 2 == 0)
        {
            b.push_back(i);
        }
        else
        {
            a.push_back(i);
        }
    }

    std::vector<int> v = {1};
    bool flag = true;

    while (!a.empty() || !b.empty())
    {
        bool found = false;

        if (flag)
        {
            for (auto it = b.begin(); it != b.end(); ++it)
            {
                int tmp = *it;
                if (is_prime[v.back() + tmp])
                {
                    v.push_back(tmp);
                    b.erase(it);
                    found = true;
                    break;
                }
            }
        }
        else
        {
            for (auto it = a.begin(); it != a.end(); ++it)
            {
                int tmp = *it;
                if (is_prime[v.back() + tmp])
                {
                    v.push_back(tmp);
                    a.erase(it);
                    found = true;
                    break;
                }
            }
        }

        if (!found)
        {
            flag = !flag;
            if (flag)
            {
                for (auto it = b.begin(); it != b.end(); ++it)
                {
                    int tmp = *it;
                    if (is_prime[v.back() + tmp])
                    {
                        v.push_back(tmp);
                        b.erase(it);
                        found = true;
                        break;
                    }
                }
            }
            else
            {
                for (auto it = a.begin(); it != a.end(); ++it)
                {
                    int tmp = *it;
                    if (is_prime[v.bac
                        k() + tmp])
                    {
                        v.push_back(tmp);
                        a.erase(it);
                        found = true;
                        break;
                    }
                }
            }
        }

        if (!found)
            break;

        flag = !flag;
    }

    for (int x : v)
        std::cout << x << " ";
    std::cout << "\n";

    return 0;
}
