#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct mang
{
    ll value, time;
};
bool cmp(mang c, mang b)
{
    return (c.time < b.time || (c.time == b.time && c.value > b.value));
}
ll n, a, b, i, res = 0, minind(0), k;
struct grter
{
    bool operator()(mang x, mang y)
    {
        return (x.value < y.value || (x.value == y.value && x.time > y.time));
    }
};
mang sol[100009];
priority_queue<mang, vector<mang>, grter> pq;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("peach.inp", "r", stdin);
    freopen("peach.out", "w", stdout);

    map<ll, ll> realtime;
    ll check(1);
    cin >> n >> a >> b;
    for (i = 1; i <= n; i++)
    {
        cin >> sol[i].time >> sol[i].value;
    }
    sort(sol + 1, sol + n + 1, cmp);
    for (i = 1; i <= n; i++)
    {
        if (sol[i].time >= a)
        {
            minind = sol[i].time;
            k = i;
            break;
        }
    }
    for (i = 1; i <= n; i++)
    {
        if (sol[i].time < minind)
        {
            pq.push(sol[i]);
        }
        else
            break;
        while (pq.size() > 1)
        {
            pq.pop();
        }
    }
    for (i = a; i < b; i++)
    {
        while (sol[k].time == i && check == 1)
        {
            pq.push(sol[k]);
            k++;
        }

        if (pq.size() > 1)
        {
            res += pq.top().value;
            pq.pop();
        }
    }

    cout << res;
}
