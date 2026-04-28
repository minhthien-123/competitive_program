#include <bits/stdc++.h>
#define task "o"
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

int n, q;
int d[maxn + 7], res[maxn + 7];
bool chon[maxn + 7];
std::map<int, int> mp[maxn + 7];
int result = 0;

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

    std::cin >> n >> q;

    while (q--)
    {
        char type;
        int v, u, c;
        std::cin >> type >> v >> u >> c;
        long long ans = 0;

        if (type == '+')
        {
            mp[u][c]++;
            mp[v][c]++;
            if (mp[u][c] == 2)
            {
                d[c]++;
            }
            if (mp[v][c] == 2)
            {
                d[c]++;
            }
            res[c]++;
            ans++;

            if (d[c])
            {
                if (!chon[c])
                {
                    ans -= res[c];
                }
                else
                {
                    ans--;
                }
                chon[c] = true;
            }
        }
        else
        {
            mp[u][c]--;
            mp[v][c]--;
            if (mp[u][c] == 1)
            {
                d[c]--;
            }
            if (mp[v][c] == 1)
            {
                d[c]--;
            }

            res[c]--;
            ans--;
            if (!d[c])
            {
                if (chon[c])
                {
                    ans += res[c] + 1;
                }
                chon[c] = false;
            }
            else
            {
                ans++;
            }
        }

        result += ans;
        std::cout << result << "\n";
    }

    return 0;
}
