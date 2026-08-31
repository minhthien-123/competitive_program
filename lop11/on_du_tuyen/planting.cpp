#include <bits/stdc++.h>
#define task "planting"
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

int n, L;
int sz[maxn + 7], del[maxn + 7];
std::vector<ii> adj[maxn + 7];

void countChild(int u, int p)
{
    sz[u] = 1;
    for (auto [v, w] : adj[u])
        if (v != p && !del[v])
        {
            countChild(v, u);
            sz[u] += sz[v];
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

    std::cin >> n >> L;


    return 0;
}
