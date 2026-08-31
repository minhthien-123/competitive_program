#include <bits/stdc++.h>
#define task "day_con"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

struct node{
    int gt,id;
};

struct query{
    int k,id,dau,cuoi;
};

const int maxn = 1e5 + 7;

int n, q;
node a[maxn];
query qe[maxn];
int kq[maxn], bit[maxn];

int count(int x){
    int ans = 0;
    while(x){
        ans += bit[x];
        x -= x & -x;
    }
    return ans;
}

void update(int x, int k){
    while(x <= n){
        bit[x] += k;
        x += x & -x;
    }
}

bool cmp1(query a, query b)
{
    return a.k > b.k;
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

    std::cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        int x;
        std::cin >> x;
        a[i].gt = x;
        a[i].id = i;
    }

    for (int i = 1; i <= q; i++)
    {
        int x;
        std::cin >> x;
        qe[i].dau = 1;
        qe[i].cuoi = n;
        qe[i].k  = x;
        qe[i].id = i;
        kq[i] = n;
    }

    std::sort(qe + 1, qe + q + 1, cmp1);

    int st = 1;
    for (int i = 1; i <= q && st <= n;)
    {
        if (st <= n && qe[i].k < a[st].gt)
        {
            update(a[st].id, 1);
            st++;
        }
        else
        {
            kq[qe[i].id] = count(qe[i].cuoi) - count(qe[i].dau - 1);
            i++;
        }
    }

    for (int i = 1; i <= q; i++)
    {
        std::cout << kq[i] << '\n';
    }

    return 0;
}
