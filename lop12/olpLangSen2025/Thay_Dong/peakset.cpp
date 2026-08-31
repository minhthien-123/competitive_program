#include <bits/stdc++.h>
#define task ""
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

int n, m;
std::vector<std::string> v1, v2, v;
std::map<std::string, int> mp1, mp2;

std::mt19937_64 rd(std::chrono::steady_clock::now().time_since_epoch().count());
#define rd rand

int Rand(int l, int r)
{
    assert(l <= r);
    return l + rd() % (r - l + 1);
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

    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        std::string s;
        std::cin >> s;
        v.pb(s);
    }

    for (int i = 0; i < n; i++)
    {
        std::string s = v[i];
        for (int j = 0; j < m; j++)
        {
            if (s[j] == '*')
            {
                int tmp = Rand(1, 1000);
                if (tmp % 2 == 0)
                {
                    s[j] = '0';
                }
                else
                {
                    s[j] = '1';
                }
            }
        }
        v1.pb(s);
    }

    for (int i = 0; i < n; i++)
    {
        std::string s = v[i];
        for (int j = 0; j < m; j++)
        {
            if (s[j] == '*')
            {
                int tmp = Rand(1, 1000);
                if (tmp % 2 == 0)
                {
                    s[j] = '0';
                }
                else
                {
                    s[j] = '1';
                }
            }
        }
        v2.pb(s);
    }

    int cnt1 = 0, cnt2 = 0;
    for (auto i : v1)
    {
        if (mp1[i] == 0)
        {
            cnt1++;
        }
        mp1[i]++;
    }
    for (auto i : v2)
    {
        if (mp2[i] == 0)
        {
            cnt2++;
        }
        mp2[i]++;
    }

    if (cnt1 > cnt2)
    {
        std::swap(cnt1, cnt2);
        std::swap(v1, v2);
    }

    std::cout << cnt1;
    for (auto i : v1)
    {
        std::cout << " " << i;
    }
    std::cout << "\n";
    std::cout << cnt2;
    for (auto i : v2)
    {
        std::cout << " " << i;
    }

    return 0;
}
