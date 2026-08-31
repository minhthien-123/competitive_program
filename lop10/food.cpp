#include <bits/stdc++.h>
#define task "food"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e6 + 7;

int n, k, res;
int a[maxn], m[maxn], f[maxn];
std::deque<int> dq;

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

    std::cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }

    for (int i = 1; i <= n; i++)
    {
        while (dq.size() && a[dq.back()] >= a[i])
        {
            dq.pop_back();
        }

        dq.pb(i);

        if (dq.front() + k <= i)
        {
            dq.pop_front();
        }

        m[i] = dq.front();
    }

    for (int i = 1; i <= n; i++)
    {
        res += a[m[i]];
    }

    std::cout << res * 2 << "\n";

    /*for (int i = 1; i <= n; i++)
    {
        std::cout << m[i] << " ";
    }
    std::cout << "\n";*/

    for (int i = 1; i <= n; i++)
    {
        f[m[i]]++;
    }

    /*int cnt = 1;
    for (int i = 1; i < n; i++)
    {
        if (m[i] == m[i + 1])
        {
            if (cnt == k)
            {
                f[i - k + 2] = cnt * 2;
                cnt = 1;
            }
            else
            {
                cnt++;
            }
        }
        else
        {
            f[i - cnt + 1] = cnt * 2;
            cnt = 1;
        }
    }

    f[n - cnt + 1] = cnt * 2;*/

    /*int i = 1, j = 1;
    while (i < n)
    {
        while (j <= n && (j - i + 1) <= k && m[i] == m[j])
        {
            j++;
            f[i] += 2;
        }

        i = j;
    }*/

    for (int i = 1; i <= n; i++)
    {
        std::cout << f[i] * 2 << " ";
    }

    return 0;
}
