#include <bits/stdc++.h>
#define task "game"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 2e5;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;

int n, t, a, b;
int k[maxn + 7];
int pre[maxn + 7];

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> n >> t >> a >> b;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> k[i];
    }

    std::priority_queue<int> cur;
    std::priority_queue<int, std::vector<int>, std::greater<>> pq;

    int sum = 0, ans = 0;

    for (int i = 1; i <= n; i++)
    {
        if (i * b > t)
        {
            break;
        }

        cur.push(k[i]);

        int p = t - i * b;
        p = p / (a - b);
        if (p > i)
        {
            p = i;
        }

        while (pq.size() <= p && cur.size())
        {
            int tmp = cur.top();
            cur.pop();
            pq.push(tmp);
            sum += tmp;
        }

        while (pq.size() > p)
        {
            int tmp = pq.top();
            pq.pop();
            cur.push(tmp);
            sum -= tmp;
        }

        while (cur.size() && pq.size() && cur.top() > pq.top())
        {
            int x = cur.top();
            cur.pop();
            int y = pq.top();
            pq.pop();
            sum += x - y;
            cur.push(y);
            pq.push(x);
        }

        ans = std::max(ans, sum);
    }

    std::cout << ans;

    return 0;
}