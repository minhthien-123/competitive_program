#include <bits/stdc++.h>
#define task "threenum"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5 + 7;
const int inf = 1e18 + 7;

struct tree
{
    int MinAm1, MinAm2, MinAm3, MaxAm1, MaxAm2;
    int MinDg1, MinDg2, MinDg3, MaxDg1, MaxDg2;
};

int n, q;
int a[maxn];
tree st[4 * maxn];

void build(int id, int l, int r)
{
    if (l == r)
    {
        if (a[l] > 0)
        {
            st[id].MinAm1 = a[l];
            st[id].MaxAm1 = a[r];
            st[id].MinAm2 = st[id].MinAm3 = inf;
            
        }
    }
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    return 0;
}
