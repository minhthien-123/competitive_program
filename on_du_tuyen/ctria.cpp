#include <bits/stdc++.h>
#define task "ctria"
#define _Thiendeptrai_ signed main()
#define ll long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 100000 + 5;
const ll inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;
const int lg = 20;

ll add(ll x, ll y)
{
    return (x + y + 2 * mod) % mod;
}
ll sub(ll x, ll y)
{
    return (x - y + 2 * mod) % mod;
}
ll mul(ll x, ll y)
{
    return (x * y) % mod;
}

std::vector<int> adj[5];
int n;
ll a[maxn];

_Thiendeptrai_
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task ".inp", "r"))
    {
        std::freopen(task ".inp", "r", stdin);
        std::freopen(task ".out", "w", stdout);
    }

    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }

    std::deque<std::pair<ll, int>> minD;
    std::deque<std::pair<ll, int>> maxD;

    int l = 1;
    int best = 1;
    for (int r = 1; r <= n; r++)
    {
        while (!minD.empty() && minD.back().first > a[r])
        {
            minD.pop_back();
        }
        minD.emplace_back(a[r], r);
        while (!maxD.empty() && maxD.back().first < a[r])
        {
            maxD.pop_back();
        }
        maxD.emplace_back(a[r], r);

        while (l <= r)
        {
            int len = r - l + 1;
            bool ok = true;
            if (len >= 3)
            {
                while (!minD.empty() && minD.front().second < l)
                {
                    minD.pop_front();
                }
                while (!maxD.empty() && maxD.front().second < l)
                {
                    maxD.pop_front();
                }
                if ((int)minD.size() >= 2 && !maxD.empty())
                {
                    ll mn1 = minD[0].first;
                    ll mn2 = minD[1].first;
                    ll mx = maxD.front().first;
                    if (mn1 + mn2 <= mx)
                    {
                        ok = false;
                    }
                }
                else
                {
                    ok = false;
                }
            }
            if (ok)
            {
                break;
            }
            l++;
        }

        best = std::max(best, r - l + 1);
    }

    std::cout << best << '\n';
    return 0;
}
