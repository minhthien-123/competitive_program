#include <bits/stdc++.h>
#define task "money"
#define _Thiendeptrai_ signed main()
#define ll long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e4;
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

std::vector<int> adj[maxn + 7];
int n, m;
ll a[maxn + 7];
ll f[maxn + 7];

void sub1()
{
    std::sort(a + 1, a + n + 1, std::greater<int>());

    while (m--)
    {
        ll s;
        std::cin >> s;

        int S = 0;
        ll V = 0;

        for (int k = n; k >= 1; k--)
        {
            bool check = false;

            for (int j = 1; j <= n; j++)
            {
                std::vector<ll> v;
                for (int i = 1; i <= n; ++i)
                {
                    if (a[i] >= a[j])
                    {
                        v.pb(a[i]);
                    }
                }

                if (v.size() < k)
                {
                    continue;
                }

                std::sort(v.begin(), v.end());
                ll sum = 0;
                for (int i = 0; i < k; i++)
                {
                    sum += v[i];
                    if (sum > s)
                    {
                        break;
                    }
                }

                if (sum <= s)
                {
                    S = k;
                    V = a[j];
                    check = true;
                    break;
                }
            }

            if (check)
            {
                break;
            }
        }

        std::cout << S << " " << V << "\n";
    }
}

void sub2()
{
    std::sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
    {
        f[i] = f[i - 1] + a[i];
    }

    while (m--)
    {
        ll s;
        std::cin >> s;
        ll S = std::upper_bound(f, f + n + 1, s) - f - 1;

        if (S <= 0)
        {
            std::cout << "0 0\n";
            continue;
        }

        int l = 0, r = n;
        int ans = -1;

        while (l <= r)
        {
            int mid = (l + r) / 2;
            int tmp = a[mid];

            int pos = std::lower_bound(a + 1, a + n + 1, tmp) - a;

            if (n - pos + 1 < S)
            {
                r = mid - 1;
                continue;
            }

            ll sum = f[pos + S - 1] - f[pos - 1];
            if (sum <= s)
            {
                ans = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }

        ll V = 0;
        if (ans == -1)
        {
            V = 0;
        }
        else
        {
            V = a[ans];
        }

        std::cout << S << " " << V << "\n";
    }
}

_Thiendeptrai_
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
        std::cin >> a[i];
    }

    if (n <= 100)
    {
        sub1();
    }
    else
    {
        sub2();
    }

    return 0;
}
