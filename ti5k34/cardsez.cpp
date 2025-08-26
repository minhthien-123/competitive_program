#include <bits/stdc++.h>
#define task "cardsez"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 100000;
int n, x;
int a[maxn];

void move(int i, int m, int j) {
    std::vector<int> tmp(a + i - 1, a + i - 1 + m);
    if (j < i) {
        for (int k = i - 1; k >= j; --k) {
            a[k + m - 1] = a[k - 1];
        }
        for (int k = 0; k < m; ++k) {
            a[j + k - 1] = tmp[k];
        }
    } else {
        for (int k = i + m - 1; k < j + m - 1; ++k) {
            a[k - m] = a[k];
        }
        for (int k = 0; k < m; ++k) {
            a[j - 1 + k] = tmp[k];
        }
    }
}

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    //std::freopen(task".inp", "r", stdin);
    //std::freopen(task".out", "w", stdout);

    std::cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
        a[i - 1] = i;
    }
    for (int k = 0; k < x; ++k) {
        int i, m, j;
        std::cin >> i >> m >> j;
        move(i, m, j);
    }
    for (int i = 1; i <= n; ++i) {
        std::cout << a[i - 1] << " ";
    }
    std::cout << '\n';
    return 0;

    return 0;
}

