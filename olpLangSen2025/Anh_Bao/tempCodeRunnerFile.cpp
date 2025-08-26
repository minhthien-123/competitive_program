#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1000000009;

int n, m;
vector<ll> a, F, PF; // a: mảng gốc; F[i]=Fibonacci thứ i; PF prefix-sum của F
struct Node
{
    ll sum;
    int lazy; // nếu lazy = d>0 nghĩa là node này cần cộng F_d, F_{d+1},...
} st[4 * 300000 + 5];

inline ll add(ll x, ll y)
{
    x += y;
    if (x >= MOD)
        x -= MOD;
    return x;
}
inline ll sub(ll x, ll y)
{
    x -= y;
    if (x < 0)
        x += MOD;
    return x;
}

// build
void build(int id, int l, int r)
{
    if (l == r)
    {
        st[id].sum = a[l] % MOD;
    }
    else
    {
        int mid = (l + r) >> 1;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
        st[id].sum = add(st[id << 1].sum, st[id << 1 | 1].sum);
    }
    st[id].lazy = 0;
}

// đẩy lazy xuống con
void push(int id, int l, int r)
{
    int d = st[id].lazy;
    if (d == 0)
        return;
    int mid = (l + r) >> 1;
    int lenL = mid - l + 1;
    int lenR = r - mid;
    // con trái
    {
        ll S = sub(PF[d + lenL - 1], PF[d - 1]);
        st[id << 1].sum = add(st[id << 1].sum, S);
        st[id << 1].lazy = (st[id << 1].lazy + d) % (MOD);
    }
    // con phải, bắt đầu từ F_{d + lenL}
    {
        int d2 = d + lenL;
        ll S = sub(PF[d2 + lenR - 1], PF[d2 - 1]);
        st[id << 1 | 1].sum = add(st[id << 1 | 1].sum, S);
        st[id << 1 | 1].lazy = (st[id << 1 | 1].lazy + d2) % (MOD);
    }
    st[id].lazy = 0;
}

// cập nhật [u..v]: cộng Fibonacci bắt đầu F_1 tại u
void update(int id, int l, int r, int u, int v)
{
    if (v < l || r < u)
        return;
    if (u <= l && r <= v)
    {
        int d = l - u + 1; // F_d cộng vào a[l]
        int len = r - l + 1;
        ll S = sub(PF[d + len - 1], PF[d - 1]);
        st[id].sum = add(st[id].sum, S);
        st[id].lazy = (st[id].lazy + d) % (MOD);
        return;
    }
    push(id, l, r);
    int mid = (l + r) >> 1;
    update(id << 1, l, mid, u, v);
    update(id << 1 | 1, mid + 1, r, u, v);
    st[id].sum = add(st[id << 1].sum, st[id << 1 | 1].sum);
}

// truy vấn tổng [u..v]
ll query(int id, int l, int r, int u, int v)
{
    if (v < l || r < u)
        return 0;
    if (u <= l && r <= v)
    {
        return st[id].sum;
    }
    push(id, l, r);
    int mid = (l + r) >> 1;
    return add(
        query(id << 1, l, mid, u, v),
        query(id << 1 | 1, mid + 1, r, u, v));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    // 1) Tính Fibonacci và prefix-sum PF
    F.assign(n + m + 5, 0);
    PF.assign(n + m + 5, 0);
    F[1] = 1;
    for (int i = 2; i < (int)F.size(); i++)
    {
        F[i] = add(F[i - 1], F[i - 2]);
    }
    for (int i = 1; i < (int)PF.size(); i++)
    {
        PF[i] = add(PF[i - 1], F[i]);
    }

    // 2) Build
    build(1, 1, n);

    // 3) Xử lý truy vấn
    while (m--)
    {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1)
        {
            update(1, 1, n, l, r);
        }
        else
        {
            cout << query(1, 1, n, l, r) << "\n";
        }
    }
    return 0;
}
