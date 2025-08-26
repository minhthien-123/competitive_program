#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct index
{
    ll beg;
    ll en;
    ll dex;
};

index a[1000005], ans;
ll n, i, j, x, y, res[1000005], d;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("cover.inp", "r", stdin);
    // freopen("cover.out", "w", stdout);

    cin >> n >> x >> y;
    for (i = 1; i <= n; i++)
    {
        cin >> a[i].beg >> a[i].en;
        a[i].dex = i;
    }

    sort(a, a + n, [](ll i, ll j)
         {
        if (a[i].beg == a[j].beg) return a[i].en < a[i].en;
        return a[i].beg < a[j].beg; });

    // for (i = 1; i <= n; i++) cout << a[i].beg << " " << a[i].en << "\n";

    i = 1;
    while (x < y)
    {
        ans.beg = -1;
        for (i = 1; i <= n && a[i].beg <= x; i++)
        {
            if (ans.beg == -1 || a[i].en > a[ans.beg].en)
            {
                ans.beg = i;
                j = a[i].dex;
            }
        }

        if (ans.beg == -1 || a[ans.beg].en < x)
        {
            d = -1;
            break;
        }

        res[++d] = j;
        x = a[ans.beg].en;
    }

    // if (ans.beg == -1 || ans.en != y) d = -1;

    cout << d << "\n";
    for (i = 1; i <= d; i++)
        cout << res[i] << " ";

    // cout << "\n\n";
    // cout << ans.beg << " " << ans.en;
}
