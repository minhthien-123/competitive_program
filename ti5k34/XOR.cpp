#include <bits/stdc++.h>
#define task "xor"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 5e5;
const int lg = 30;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

struct trie
{
    int c[2];
    int cnt, cntS;
} t[maxn * 31 + 7];

int n;
int sz = 1;
int a[maxn + 7];

void init(int i)
{
    t[i].c[0] = t[i].c[1] = -1;
    t[i].cnt = t[i].cntS = 0;
}

void add(int x)
{
    int pos = 0;
    t[pos].cntS++;
    for (int i = lg; i >= 0; i--)
    {
        int c = (x >> i) & 1;
        if (t[pos].c[c] == -1)
        {
            t[pos].c[c] = sz;
            init(sz);
            sz++;
        }
        pos = t[pos].c[c];
        t[pos].cntS++;
    }
    t[pos].cnt++;
}

int query(int x)
{
    int res = 0;
    std::stack<ii> st;
    st.push({0, lg});

    while (!st.empty())
    {
        int pos = st.top().fi;
        int len = st.top().se;
        st.pop();
        if (pos < 0)
            continue;

        if (len < 0)
        {
            res += t[pos].cntS;
            continue;
        }

        int c = (x >> len) & 1;
        if (c == 0)
        {
            if (t[pos].c[0] != -1)
                st.push({t[pos].c[0], len - 1});
        }
        else
        {
            if (t[pos].c[0] != -1)
                res += t[t[pos].c[0]].cntS;
            if (t[pos].c[1] != -1)
                st.push({t[pos].c[1], len - 1});
        }
    }

    return res;
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
        std::cin >> a[i];
    }

    init(0);

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += query(a[i]);
        add(a[i]);
    }

    std::cout << ans << "\n";

    return 0;
}