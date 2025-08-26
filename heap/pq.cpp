#include <bits/stdc++.h>
#define task "pq"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

int n, a[maxn + 7];
std::priority_queue<int> pq;

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    if (std::fopen(task ".inp", "r"))
    {
        std::freopen(task ".inp", "r", stdin);
        std::freopen(task ".out", "w", stdout);
    }

    std::cin >> n;
    while (n--)
    {
        std::string s;
        std::cin >> s;
        if (s[0] == '+')
        {
            s.erase(s.begin() + 0);
            int x = atol(s.c_str());
            pq.push(x);
        }
        else
        {
            if (!pq.empty())
            {
                int x = pq.top();
                while (!pq.empty() && pq.top() == x)
                {
                    pq.pop();
                }
            }
        }
    }

    int d = 0;
    while (pq.size())
    {
        int x = pq.top();
        //std::cout << x << "\n";
        while (pq.size() && pq.top() == x)
        {
            pq.pop();
        }

        ++d;
        a[d] = x;
    }

    std::cout << d << "\n";
    for (int i = 1; i <= d; i++)
    {
        std::cout << a[i] << " ";
    }

    return 0;
}
