#include <bits/stdc++.h>
#define task "udtseq2"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5 + 7;

int n, q;
int a[maxn];

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r")){
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> n >> q;

    while (q--)
    {
        int l, r, k;
        std::cin >> l >> r >> k;
        a[l] += k;
        a[r + 1] -= k * (r - l + 1);
        for (int i = 1; i <= n; i++)
        {
            std::cout << a[i] << " ";
        }
        std::cout << "\n";
    }

    for (int i = 1; i <= n; i++)
    {
        a[i] += a[i - 1];
    }

    for (int i = 1; i <= n; i++)
    {
        a[i] += a[i - 1];
    }

    for (int i = 1; i <= n; i++)
    {
        std::cout << a[i] << " ";
    }

    return 0;
}

// 0 0 0 0 0
// 1 2 3 -3 0
// 0 2 4 6 8 -8
//
