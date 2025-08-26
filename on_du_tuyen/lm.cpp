#include <bits/stdc++.h>
#define task "lm"
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
std::string s;
std::vector<int> a;
bool vis[maxn + 7];
int par[maxn + 7], trace[maxn + 7];
std::deque<int> dq;

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> n >> s;
    for (auto c : s)
    {
        a.pb(c - '0');
    }

    std::sort(a.begin(), a.end());

    for (int i : a)
    {
        if (i == 0)
        {
            continue;
        }
        int r = i % n;
        if (!vis[r])
        {
            vis[r] = true;
            par[r] = -1;
            trace[r] = i;
            dq.pb(r);
        }
    }

    bool flag = false;
    while (dq.size())
    {
        int r = dq.front();
        dq.pop_front();

        if (r == 0)
        {
            flag = true;
            break;
        }

        for (int i : a)
        {
            int nr = (r * 10 + i) % n;
            if (!vis[nr])
            {
                vis[nr] = true;
                par[nr] = r;
                trace[nr] = i;
                dq.pb(nr);
                if (nr == 0)
                {
                    flag = true;
                    break;
                }
            }
        }
    }

    if (!flag)
    {
        std::cout << 0;
        exit(0);
    }

    std::string ans;
    for (int path = 0; path != -1; path = par[path])
    {
        ans.pb(char('0' + trace[path]));
    }
    std::reverse(ans.begin(), ans.end());

    std::cout << ans;

    return 0;
}
