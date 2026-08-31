#include <bits/stdc++.h>
#define task "eop"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e6;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;

int n;
std::string a;
int odd_cnt, even_cnt;

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
    std::cin >> a;
    a = " " + a;

    for (int i = 1; i <= n; i++)
    {
        int tmp = a[i] - '0';
        if (tmp % 2 == 0)
        {
            even_cnt++;
        }
        else
        {
            odd_cnt++;
        }
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        int tmp = a[i] - '0';
        if (tmp % 2 == 0)
        {
            even_cnt--;
            cnt += odd_cnt;
        }
        else
        {
            odd_cnt--;
            cnt += even_cnt;
        }
    }

    std::cout << cnt;

    return 0;
}
