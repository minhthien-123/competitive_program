#include <bits/stdc++.h>
#define task "b3"
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

std::string s;
int n;
int bit[maxn + 7][30];

void update(int id, int c, int k)
{
    for (id; id <= n; id += id & (-id))
    {
        bit[id][c] += k;
    }
}

int get(int id, int c)
{
    int ans = 0;
    for (id; id > 0; id -= id & (-id))
    {
        ans += bit[id][c];
    }

    return ans;
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

    std::cin >> s;
    n = s.size();
    s = " " + s;

    for (int i = 1; i <= n; i++)
    {
        update(i, s[i] - 'a', 1);
    }

    int q;
    std::cin >> q;
    while (q--)
    {
        int type;
        std::cin >> type;
        if (type == 1)
        {
            int pos;
            char c;
            std::cin >> pos >> c;
            update(pos, s[pos] - 'a', -1);
            update(pos, c - 'a', 1);
            s[pos] = c;
        }
        else
        {
            int l, r;
            std::cin >> l >> r;
            int cnt = 0;
            for (int i = 0; i < 26; i++)
            {
                int tmp = get(r, i) - get(l - 1, i);
                if (tmp > 0)
                {
                    cnt++;
                }
            }
            std::cout << cnt << "\n";
        }
    }

    return 0;
}
