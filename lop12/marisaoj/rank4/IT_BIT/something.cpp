#include <bits/stdc++.h>
#define task "swap"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;

int n, q;
int l[maxn + 7], r[maxn + 7];

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        l[i] = i - 1;
        r[i] = i + 1;
        if (i == n)
        {
            r[i] = 0;
        }
    }

    int s = 1;

    while (q--)
    {
        int a, b;
        std::cin >> a >> b;
        if (a == b)
        {
            continue;
        }

        int L = l[a], R = r[a];
        if (L != 0)
        {
            r[L] = R;
        }
        else
        {
            s = R;
        }
        if (R != 0)
        {
            l[R] = L;
        }

        int tmp = l[b];
        l[a] = tmp;
        r[a] = b;
        l[b] = a;
        if (tmp != 0)
        {
            r[tmp] = a;
        }
        else
        {
            s = a;
        }
    }

    std::vector<int> ans;
    for (int i = s; i != 0; i = r[i])
    {
        ans.pb(i);
    }

    for (int i : ans)
    {
        std::cout << i << " ";
    }

    return 0;
}
