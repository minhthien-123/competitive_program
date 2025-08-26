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
const int inf  = 1e18;

int n;
bool isPrime[maxn + 7];
int a[maxn + 7];

void sieve()
{
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= maxn; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= maxn; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);


    std::ifstream inp(task".inp");
    std::ifstream out(task".out");

    inp >> n;
    sieve();
    inp.close();
    std::vector<int> v = {0};
    int i = 1, x;
    while (out >> x)
    {
        a[i] = x;
        v.pb(x);
        i++;
    }
    std::sort(v.begin(), v.end());
    out.close();
    if (v.size() - 1 != 2 * n)
    {
        std::cout << "WRONG ANSWER\n";
        return 0;
    }
    for (int i = 1; i <= 2 * n; i++)
    {
        if (v[i] != i)
        {
            std::cout << "WRONG ANSWER\n";
            return 0;
        }
    }
    for (int i = 1; i < 2 * n; i++)
    {
        if (!isPrime[a[i] + a[i + 1]])
        {
            std::cout << "WRONG ANSWER\n";
            return 0;
        }
    }

    std::cout << "ACCEPTED\n";
    return 0;
}
