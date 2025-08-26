#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll N = 1e5;

ll n, i, j, u, v, a[N + 5], st[N * 4], q;

void buildTree(ll id, ll l, ll r)
{
    if (l == r)
    {
        st[id] = a[l];
        return;
    }

    ll mid = (l + r) / 2;

    buildTree(id * 2, l, mid);
    buildTree(id * 2 + 1, mid + 1, r);

    // st[id] = st[id * 2] + st[id * 2 + 1];
    sum = max(st[id * 2] + st[id * 2 + 1], max(st[id * 2], st[id * 2 + 1]));
}

ll get(ll id, ll l, ll r, ll i, ll j)
{
    if (j < l || r < i)
        return LLONG_MIN;
    if (i <= l && r <= j)
        return st[id];

    ll mid = (l + r) / 2;
    return max(get(id * 2, l, mid, i, j), get(id * 2 + 1, mid + 1, r, i, j));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("seg.inp", "r", stdin);
    freopen("seg.out", "w", stdout);

    cin >> n >> q;
    for (i = 1; i <= n; i++)
        cin >> a[i];
    buildTree(1, 1, n);
    // for (i = 1; i <= 4 * n; i++) cout << st[i] << " ";

    while (q--)
    {
        cin >> u >> v;
        cout << get(1, 1, n, u, v) << "\n";
    }
}