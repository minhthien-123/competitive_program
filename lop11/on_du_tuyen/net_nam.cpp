#include <bits/stdc++.h>
#define task "net"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 3e5;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;

int n, m;
ii a[maxn + 7];

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i].fi >> a[i].se;
    }

    std::sort(a + 1, a + n + 1);

    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    std::multiset<int> mts;

    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        int s = a[i].fi;
        int t = a[i].se;

        while (pq.size() && pq.top() <= s)
        {
            int s1 = pq.top();
            pq.pop();
            int t1 = s1 + m;
            if (t1 > s)
            {
                mts.ins(t1);
            }
        }

        while (mts.size())
        {
            auto it = mts.begin();
            if (*it <= s)
            {
                mts.erase(it);
            }
            else
            {
                break;
            }
        }

        if (mts.size())
        {
            ans++;
            auto it = mts.begin();
            mts.erase(it);
        }
        pq.push(s + t);
    }

    std::cout << ans;

    return 0;
}
