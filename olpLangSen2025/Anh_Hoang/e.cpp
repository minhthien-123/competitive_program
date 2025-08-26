#include <bits/stdc++.h>
#define task ""
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 4e6;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

int n;
int pre[maxn + 7], cnt[maxn + 7];
int ans = 0;
std::string s;

void dnc(int l, int r)
{
    if (l == r)
    {
        ans++;
        return;
    }

    int mid = (l + r) / 2;
    int u, v = mid;
    int maxSuf = pre[mid - 1];
    int res = 0;
    int last = -n;

    for (u = mid; u >= l; u--)
    {
        maxSuf = std::max(maxSuf, pre[u - 1]);

        if (last != -n)
        {
            int now = maxSuf - pre[u - 1];
            if (last < now)
            {
                for (int i = last; i < now; i++)
                {
                    res -= cnt[i];
                }
            }
            else if (last > now)
            {
                for (int i = last - 1; i >= now; i--)
                {
                    res += cnt[i];
                }
            }
        }

        while (v != r && pre[v] <= maxSuf)
        {
            v++;
            cnt[pre[v]]++;
            if (pre[v] >= maxSuf - pre[u - 1])
            {
                res++;
            }
        }

        ans += res;
        last = maxSuf - pre[u - 1];
    }

    for (int i = mid + 1; i <= v; i++)
    {
        cnt[pre[i]] = 0;
    }

    int maxPre = pre[mid];
    u = mid + 1;
    res = 0;
    last = -n;

    for (v = mid + 1; v <= r; v++)
    {
        maxPre = std::max(maxPre, pre[v - 1]);

        if (last != -n)
        {
            int now = maxPre - pre[v];
            if (last < now)
            {
                for (int i = last; i < now; i++)
                {
                    res -= cnt[i];
                }
            }
            else if (last > now)
            {
                for (int i = last - 1; i >= now; i--)
                {
                    res += cnt[i];
                }
            }
        }

        while (u != l && pre[u - 2] < maxPre)
        {
            u--;
            cnt[pre[u - 1]]++;
            if (pre[u - 1] >= maxPre - pre[v])
                res++;
        }

        ans += res;
        last = maxPre - pre[v];
    }

    for (int i = u; i <= mid; i++)
    {
        cnt[pre[i - 1]] = 0;
    }

    dnc(l, mid);
    dnc(mid + 1, r);
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

    std::cin >> n >> s;
    s = " " + s;

    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1] + (s[i] == '(' ? 1 : -1);
    }

    dnc(1, n);

    std::cout << ans;
    return 0;
}
