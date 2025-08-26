#include <bits/stdc++.h>
#define task "odsports"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define pb push_back
#define ins insert

const int maxn = 1e5;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

int n, r, q;
int v[maxn + 7], s[maxn + 7];
std::vector<int> vec[maxn + 7];

bool check(int x)
{
    for (int i = 1; i <= n; i++)
    {
        vec[i].clear();
    }

    for (int i = 1; i <= n; i++)
    {
        int tmp = s[i] / x;
        int l = std::max(1LL, v[i] - tmp);
        int r = std::min(n, v[i] + tmp);
        vec[l].pb(r);
    }

    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

    for (int i = 1; i <= n; i++)
    {
        for (int x : vec[i])
        {
            pq.push(x);
        }

        if (pq.empty())
        {
            return false;
        }
        int top = pq.top();
        if (top < i)
        {
            return false;
        }
        else
        {
            pq.pop();
        }
    }
    return true;
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

    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> v[i];
    }

    int l = 1, r = 0, ans = -1;

    for (int i = 1; i <= n; i++)
    {
        std::cin >> s[i];
        r = std::max(r, s[i]);
    }

    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (check(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    std::cin >> q;
    while (q--)
    {
        int x;
        std::cin >> x;
        std::cout << (x <= ans) << " ";
    }

    return 0;
}
