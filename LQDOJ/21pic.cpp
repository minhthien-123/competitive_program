#include <bits/stdc++.h>
#define task "21pic"
#define ll long long

struct pic{
    ll a, b;
};

bool cmp(pic x, pic y) {
    return x.a < y.a;
}

const ll maxn = 1e6 + 7;
pic x[maxn];
ll pre[maxn], mx[maxn], n, i, res = LLONG_MIN;

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen(task".inp", "r", stdin);
    std::freopen(task".out", "w", stdout);

    std::cin >> n;

    for (int i = 1; i <= n; i++)
        std::cin >> x[i].a >> x[i].b;

    std::sort(x + 1, x + n + 1, cmp);

    pre[0] = 0;
    for (i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + x[i].b;

    mx[1] = x[1].a;
    for (i = 1; i <= n; i++)
    	mx[i] = std::max(mx[i - 1], x[i].a - pre[i - 1]);

    for (i = 1; i <= n; i++)
    	res = std::max(res, (pre[i] - x[i].a) + mx[i]);

    std::cout << res;

    return 0;
}
