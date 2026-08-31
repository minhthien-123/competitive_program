#include <bits/stdc++.h>
using namespace std;

struct tree
{
    int lazy;
    int val;
};

tree st[1000005];
int a[100000 + 5], n, m;

void down(int id)
{
    int t = st[id].lazy;

    st[id * 2].lazy += t;
    st[id * 2].val += t;

    st[id * 2 + 1].lazy += t;
    st[id * 2 + 1].val += t;

    st[id].lazy = 0;
}

void update(int id, int l, int r, int x, int y, int val)
{
    if (y < l || r < x)
        return;
    if (l >= x && r <= y)
    {
        st[id].lazy += val;
        st[id].val += val;
        return;
    }

    int mid = (l + r) / 2;

    down(id);

    update(id * 2, l, mid, x, y, val);
    update(id * 2 + 1, mid + 1, r, x, y, val);

    st[id].val = max(st[id * 2].val, st[id * 2 + 1].val);
}

int get(int id, int l, int r, int x, int y)
{
    if (y < l || r < x)
        return INT_MIN;
    if (l >= x && r <= x)
        return st[id].val;

    int mid = (l + r) / 2;

    down(id);

    return max(get(id * 2, l, mid, x, y), get(id * 2 + 1, mid + 1, r, x, y));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("itlazy.inp", "r", stdin);
    freopen("itlazy.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    cin >> m;
    while (m--)
    {
        int q;
        cin >> q;
        if (q == 1)
        {
            int x, y, val;
            cin >> x >> y >> val;
            update(1, 1, n, x, y, val);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << get(1, 1, n, l, r) << "\n";
        }
    }
}
