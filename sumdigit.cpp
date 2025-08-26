#include <bits/stdc++.h>
#define task "sumdigit"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 2e3 + 7;

int cnt(int x)
{
    int res = 0;
    while (x)
    {
        res += x % 10;
        x /= 10;
    }
    return res;
}

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r")){
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    int q;

    while (q--)
    {

    }

    return 0;
}
