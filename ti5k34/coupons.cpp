#include <bits/stdc++.h>
using namespace std;
#define task "coupons"
#define int long long
#define ii pair<int, int>
#define iii pair<int, ii>
#define fi first
#define se second
#define pb push_back    

const int N = 1e5 + 9;
int n, m, k, sum = 0, vs[N];
struct mang
{
    int a, b, c;
} x[N];
bool cmp1(mang u, mang v)
{
    return u.b < v.b;
}
struct Compare
{
    bool operator()(const ii &a, const ii &b)
    {
        return a.first > b.first;
    }
};

priority_queue<ii, vector<ii>, Compare> qa, qb, qc;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (ifstream(task ".inp"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    cin >> n >> k >> m;
    for (int i = 1; i <= n; i++)
    {
        vs[i] = 0;
        cin >> x[i].a >> x[i].b;
        x[i].c = x[i].a - x[i].b;
    }
    sort(x + 1, x + n + 1, cmp1);
    int sum = 0, id, res = 0;
    for (int i = 1; i <= k; i++)
    {
        if (sum + x[i].b > m)
            break;
        sum += x[i].b;
        res++;
    }
    for (int i = 1; i <= k; i++)
    {
        qc.push({x[i].c, i});
        vs[i] = 1;
    }
    for (int i = k + 1; i <= n; i++)
    {
        //  cout<<x[i].a<<" "<<x[i].b<<"\n";
        qa.push({x[i].a, i});
        qb.push({x[i].b, i});
    }
    while (1)
    {
        while (!qa.empty() && vs[qa.top().se])
            qa.pop();
        while (!qb.empty() && vs[qb.top().se])
            qb.pop();

        int cost1 = 2e9, cost2 = 2e9;
        int id1 = -1, id2 = -1;

        if (!qa.empty())
        {
            cost1 = qa.top().fi;
            id1 = qa.top().se;
        }

        if (!qb.empty() && !qc.empty())
        {
            cost2 = qb.top().fi + qc.top().fi;
            id2 = qb.top().second;
        }

        int mn = min(cost1, cost2);
        if (mn == 2e9)
            break;

        if (sum + mn > m)
            break;

        sum += mn;
        res++;

        if (cost1 <= cost2)
        {
            vs[id1] = 1;
            qa.pop();
        }
        else
        {
            vs[id2] = 1;
            qb.pop();
            qc.pop();
            qc.push({x[id2].c, id2});
        }
    }

    cout << res;
}
