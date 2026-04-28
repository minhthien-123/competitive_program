#include <bits/stdc++.h>
#define task ""
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 200000;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;
const int S   = 450;

int n, q;
int a[maxn + 7];
int sum_block[maxn + 7];

void update(int pos, int val)
{
    int b = (pos - 1) / S;
    sum_block[b] += val - a[pos];
    a[pos] = val;
}

int get(int l, int r)
{
    if (l > r)
    {
        return 0;
    }
    int bl = (l - 1) / S;
    int br = (r - 1) / S;
    int ans = 0;
    if (bl == br)
    {
        for (int i = l; i <= r; i++)
        {
            ans += a[i];
        }
        return ans;
    }
    int L = std::min(n, (bl + 1) * S);
    for (int i = l; i <= L; i++)
    {
        ans += a[i];
    }
    int R = br * S + 1;
    for (int i = R; i <= r; i++)
    {
        ans += a[i];
    }
    for (int b = bl + 1; b <= br - 1; b++)
    {
        ans += sum_block[b];
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

    std::cin >> n >> q;

    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        sum_block[(i - 1) / S] += a[i];
    }

    while (q--)
    {
        int type, x, y;
        std::cin >> type >> x >> y;
        if (type == 1)
        {
            update(x, y);
        }
        else
        {
            std::cout << get(x, y) << "\n";
        }
    }

    return 0;
}
