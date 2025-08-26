#include <bits/stdc++.h>
#define task "permutation"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;
const int inf = 1e18;

int n, x, k;
int a[maxn + 7];
bool flag[maxn + 7];
int f[maxn + 7];
std::vector<int> p;

void init()
{
    for (int i = 0; i <= maxn; i++)
    {
        f[i] = 1;
        flag[i] = false;
        p.pb(i);
    }
    for (int i = 1; i <= maxn; i++)
    {
        f[i] = f[i - 1] * i;
    }
}

int solve1()
{
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        int cnt = 0;
        for (int j = 1; j < a[i]; j++)
        {
            if (!flag[j])
            {
                cnt++;
            }
        }
        // std::cout << cnt << " " << n - i << " " << f[n - i] << "\n";
        res += cnt * f[n - i];
        flag[a[i]] = true;
    }
    return res + 1;
}

void solve2()
{
    std::vector<int> v;
    for (int i = 0; i <= n; i++)
    {
        v.pb(i);
    }

    k--;
    for (int i = 1; i <= n; i++)
    {
        int tmp = n - i;
        int cur = f[tmp];
        int pos = k / cur;
        std::cout << p[pos + 1] << " ";
        k %= cur;
        p.erase(p.begin() + pos + 1);
    }
}

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

    n = 0;
    while (std::cin >> x)
    {
        a[++n] = x;
    }
    k = a[n--];

    // for (int i = 1; i <= n; i++)
    // {
    //     std::cout << a[i] << " ";
    // }
    // std::cout << "\n";
    // std::cout << k;
    // std::cout << "\n";

    init();
    std::cout << solve1() << "\n";
    solve2();

    return 0;
}
