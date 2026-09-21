#include <bits/stdc++.h>
#define task "P4137"
#define int long long
#define __Thien_dep_trai__ signed main()
#define ll long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define pll std::pair<ll, ll>
#define vi std::vector<int>
#define vii std::vector<ii>
#define fi first
#define se second
#define pb push_back
#define ins insert
#define sz(x) ((int)(x).size())
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define bit_set(x, pos) ((x) |= (1ULL << (pos)))
#define bit_clear(x, pos) ((x) &= ~(1ULL << (pos)))
#define all(x) x.begin(), x.end()

const int maxn = 2e5;
const ll INF = 1e18;
const int inf = 1e9;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;
const int lg = 20;
const int dx[] = {0, 1, 0, -1, -1, -1, 1, 1};
const int dy[] = {1, 0, -1, 0, -1, 1, -1, 1};

ll add(ll x, ll y)
{
    return (x + y + 2 * mod) % mod;
}
ll sub(ll x, ll y)
{
    return (x - y + 2 * mod) % mod;
}
ll mul(ll x, ll y)
{
    return (x % mod * (y % mod)) % mod;
}
ll power(ll x, ll y)
{
    if (y == 0)
    {
        return 1;
    }
    ll tmp = power(x, y / 2);
    if (y % 2 == 0)
    {
        return (tmp * tmp) % mod;
    }
    else
    {
        return tmp * tmp % mod * x % mod;
    }
}

int n, m;
int a[maxn + 7];

struct Node
{
    int lc, rc;
    long long min_pos;
};

int node_cnt;
Node st[maxn * 43];
int roots[maxn + 7];

int build(int l, int r)
{
    node_cnt++;
    int id = node_cnt;
    if (l == r)
    {
        return id;
    }
    int mid = (l + r) / 2;
    st[id].lc = build(l, mid);
    st[id].rc = build(mid + 1, r);
    return id;
}

int update(int old_id, int l, int r, int pos, int id_pos)
{
    node_cnt++;
    int id = node_cnt;
    st[id] = st[old_id];
    st[id].min_pos = 1;

    if (l == r)
    {
        st[id].min_pos = id_pos;
        return id;
    }

    int mid = (l + r) / 2;
    if (pos <= mid)
    {
        st[id].lc = update(st[old_id].lc, l, mid, pos, id_pos);
    }
    else
    {
        st[id].rc = update(st[old_id].rc, mid + 1, r, pos, id_pos);
    }
    st[id].min_pos = std::min(st[st[id].lc].min_pos, st[st[id].rc].min_pos);
    return id;
}

long long query(int id, int l, int r, int k)
{
    if (l == r)
    {
        return l;
    }
    int mid = (l + r) / 2;
    if (st[st[id].lc].min_pos < k)
    {
        return query(st[id].lc, l, mid, k);
    }
    else
    {
        return query(st[id].rc, mid + 1, r, k);
    }
}

void solve()
{
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }

    roots[0] = build(1, n);
    for (int i = 1; i <= n; i++)
    {
        if (a[i] > n + 1)
        {
            roots[i] = roots[i - 1];
        }
        else
        {
            roots[i] = update(roots[i - 1], 0, n + 1, a[i], i);
        }
    }

    for (int i = 1; i <= m; i++)
    {
        int l, r;
        std::cin >> l >> r;
        std::cout << query(roots[r], 0, n + 1, l) << "\n";
    }
}

__Thien_dep_trai__
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    if (std::fopen(task ".inp", "r"))
    {
        std::freopen(task ".inp", "r", stdin);
        std::freopen(task ".out", "w", stdout);
    }

    int tt = 1;
    // std::cin >> tt;
    while (tt--)
    {
        solve();
    }

    std::cerr << "\nTime elapsed: " << TIME << " s.\n";

    return 0;
}
/*
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⣴⣾⣿⣿⣿⣿⣷⣦⣤⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣴⣾⣿⣿⣿⣿⡿⡿⡿⠿⠿⣿⣿⣿⣿⣿⣿⣿⣷⣶⣤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣴⣿⣿⣿⣿⣿⡿⠯⣩⣾⣾⣿⣿⣿⡚⣛⣝⢕⢕⢝⢝⢽⣿⣿⣿⣷⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⣾⣿⣿⣿⣿⣿⣿⡿⣨⣿⣿⣿⣿⠿⣛⡭⢓⣿⣿⣷⣕⢷⣥⠥⢝⣿⣿⣿⡿⣿⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣾⡿⢿⠟⣭⣿⣿⣿⣫⣾⡫⣯⢿⢷⢶⢿⣶⢮⣟⣩⣴⡻⢷⡆⣿⣿⢕⢙⣿⣿⣿⣿⣿⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⡾⡛⡡⠊⣴⣿⣿⣟⢽⢟⣿⣑⣙⣾⠺⣸⡾⡏⣚⡛⣿⣯⡡⢜⣧⢝⣿⣞⡪⡹⣿⣿⣿⡏⢿⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣴⡯⡫⢪⣒⠿⣽⣿⣟⣼⣿⣿⣕⣪⣿⠯⣫⣿⡯⡭⣮⣻⣿⣯⢝⣿⣿⣬⢼⣿⣪⡫⡻⣿⣿⣿⡍⣿⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣄⣴⡿⡾⠺⡴⣾⣿⣿⢗⣟⣿⣿⠅⣶⣿⣯⢎⣾⡿⡪⣾⡧⣾⣿⠵⢕⣿⣿⣇⢵⣿⣏⡮⠪⣻⣿⡾⡮⡹⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⣿⣿⣧⣿⣴⣿⣿⢓⣟⣿⢯⢏⣵⡿⣹⣿⣺⣿⡏⡇⣿⡿⣿⣿⢹⢘⣿⣿⣯⠕⣿⣿⣿⡬⣏⢻⣿⠯⣭⢺⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣟⣼⣿⣿⣿⣿⣿⢵⣿⣿⡯⡼⡲⣿⠗⣻⣿⣾⡟⢽⢺⣿⡧⣿⡿⡧⡣⣿⣿⡿⡟⣿⣿⣿⣷⢻⡼⣿⣿⣿⠲⣻⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⣀⠀⣀⣠⡤⣾⣞⣿⣿⣿⣿⣿⣟⡭⣿⣾⣿⠀⠨⣸⡏⠀⢹⣿⣿⠘⡗⢼⣿⣿⢿⢸⡺⠺⣿⣿⣟⡢⣿⣿⣿⣿⣿⣿⢜⣿⣿⡯⣪⣧⠀⠀⠀⠀⠀⣀⡀⠀⠀⠀
⠀⠀⠀⠀⠀⠈⠙⠚⠋⣡⢟⣾⣿⣿⣿⣟⢿⠭⢵⣻⣿⣿⠀⢨⣺⡇⠀⠸⣿⣿⠀⠹⢝⣿⣿⣿⡇⢯⡪⡮⣿⡯⡪⢿⣿⣿⣿⣿⣿⣷⢛⣿⣿⣾⣾⠀⠀⠀⢀⡴⠏⠻⠛⡧⠀
⠀⠀⠀⠀⠀⠀⠀⠀⡼⣻⣿⣿⣿⣿⡟⣗⣳⢼⣏⡻⡩⠿⢤⠼⢾⣿⠀⠀⠹⢿⣇⠀⠳⣽⣿⣿⣷⡈⢮⡪⣻⣟⣒⣻⣿⣿⣿⣿⣿⣿⣕⣿⣿⣿⣿⡆⠀⠀⠘⢷⡆⣠⣙⡇⠀
⠀⠀⠀⠀⠀⠀⠀⠀⢯⣽⣿⣟⣥⢹⣵⣿⢮⣿⣷⣴⣿⣶⣾⣦⣤⣄⠀⠀⠀⠈⠉⠁⠀⠈⠙⢻⣛⡻⡎⢻⣽⣯⣆⣯⣿⣿⣿⣿⣿⣿⣧⡺⢟⣱⠞⣦⣀⡀⠀⠈⠙⠉⠉⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⠻⡎⣶⣿⣿⣫⣾⣿⠟⠋⠁⠀⠉⠉⠙⠁⠀⠀⠀⠀⠀⠀⠀⠀⣀⣴⣥⣩⠛⠲⣼⣗⢧⢖⡺⣿⣯⣺⣻⣿⣿⡄⢯⡈⠀⠀⣴⠇⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⣯⢫⣿⣿⣿⣫⣿⣿⡗⠀⢀⠂⡄⠀⠀⠀⠀⠀⠐⠳⠒⠀⠀⠀⠀⠉⠉⠙⠿⢯⣒⣼⣯⢝⣿⣮⡻⣿⣧⣪⡻⣿⡏⡸⠧⠼⣦⠉⢳⠋⢹⡆⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⢈⣿⣿⣿⣿⣿⣿⣿⡧⠢⠃⡐⠀⠀⠀⡖⠒⠤⠤⣤⣄⣀⡀⠀⠀⠀⠀⠀⠀⡀⡹⢿⣿⠗⣿⣿⣿⣾⣯⡿⡪⡿⣿⣞⡟⣵⠛⠁⠀⠀⠛⣶⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⢠⣾⣿⣿⣿⣿⣿⣿⣽⣧⠆⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⠀⠈⠉⠙⢳⡄⠀⡰⡜⡠⢁⠽⢿⣽⣿⣿⣿⣿⣿⣮⢮⣻⣗⣿⣬⣛⣿⣀⡽⠛⠋⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⣠⣿⣿⣿⣿⣿⣿⣿⣟⣿⣿⣷⣄⠀⠀⠀⠀⠹⡀⠀⠀⠀⠀⠀⠀⠀⠀⣸⠇⠀⢠⢠⢁⠎⣠⣿⣿⣿⣿⣿⣿⢿⣿⣟⣽⣿⣿⣿⣿⠈⠉⠁⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⣰⣻⣿⣿⣿⢻⣿⣿⣿⣕⣿⣿⣿⣿⣷⣦⡀⠀⠀⠁⠀⠀⠀⠀⠀⣠⡤⠖⠁⠀⠀⠀⠁⠘⢎⣸⣺⣿⣿⣿⢿⣿⣽⣿⣿⣿⣿⣿⣿⣸⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⢰⣿⡿⣿⣿⢣⣿⢿⣿⢗⣽⣿⣿⣿⣿⣿⣿⣿⣿⣶⣤⣤⣀⣀⣀⣀⣀⣀⣀⣀⣠⣤⣴⣶⣿⣿⣿⡾⣿⣿⣷⢽⣷⣿⣿⣿⣿⣿⣿⣿⣾⣧⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⢸⣾⣰⣿⣯⢞⣷⣿⣟⣅⣿⣿⣿⠿⠿⠿⠿⠿⠛⠛⠛⠿⣿⣯⡿⡫⡡⠽⣿⠽⠟⣿⣿⣿⣿⣿⣿⣺⣿⣿⣗⣿⣿⣿⣿⣿⣿⣿⣿⣽⣿⣻⣆⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⢸⣿⣇⣿⣽⢳⣿⣿⠱⣼⡟⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⣰⣿⣿⣯⠾⠚⠉⠀⠀⠀⣟⢛⡿⠛⠉⣻⣿⣿⣿⣻⡧⣿⣿⣿⣿⣿⣿⣿⣿⣿⣟⣿⣧⡀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠈⢿⡿⣯⣽⣺⣿⣟⢴⢟⣥⣛⡇⠀⠀⠀⠀⠀⠀⠀⢀⣿⣿⠋⠉⠀⠀⠀⠀⠀⠀⣻⠞⠁⠀⠀⣯⣿⣿⣿⣟⣕⣿⡿⣿⣿⣿⣿⣿⣿⣫⡯⣯⣿⣷⡀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⣠⡺⣺⡿⠿⣾⣿⢣⡭⢿⠀⠹⠖⢶⡀⠀⠀⠀⠀⠀⡼⢭⣉⡀⠀⠀⠀⠀⠀⢀⡜⠁⠀⠀⠀⠸⣿⣿⣿⣿⢷⣗⢿⣿⡿⢋⣹⣿⣿⣿⣿⡪⡿⣾⣺⣿⣄⠀⠀⠀
⠀⠀⠀⢀⡼⣯⣾⣯⣯⣽⣿⣿⠜⢦⡤⠀⠀⢲⡟⠀⠀⠀⠀⠀⢐⡇⠀⠀⠉⠛⠒⠶⠶⣶⠋⠀⠀⠀⠀⠀⣮⣾⣿⣿⣿⣟⣿⣝⢽⠞⣑⢑⣿⣿⣿⣿⡯⣯⣻⣯⣯⣽⣦⠀⠀
⠀⠀⢠⣻⣮⣿⣟⣜⢿⢽⣿⣟⠀⡸⣤⡼⠷⡶⠇⠀⠀⠀⠀⠀⢸⢤⡀⠀⠀⠀⠀⢀⡴⠁⠀⠀⠀⠀⠀⢰⣻⣿⣿⢿⣿⡯⣿⣷⢿⣇⠆⠄⣿⣿⣿⣿⣿⡿⣾⣿⣷⡿⢿⣆⠀
⠀⣰⣿⣷⣿⣿⣷⣝⣵⢽⡿⠫⠰⠸⢸⢸⠸⣿⢇⣀⣠⣄⠀⠀⢸⠀⠀⠀⠀⠉⢉⡟⠀⠀⠀⠀⠀⠀⠀⣇⣿⣿⡏⣾⣿⡿⣿⣿⣺⡻⣴⠙⢾⣿⣿⣿⣿⣷⣿⢿⣿⣿⣺⡻⡇
⢸⡧⢽⣿⣿⣿⣿⠝⣷⠻⠟⢻⡆⠊⡮⠊⣇⠟⣿⡈⠃⠼⣆⠀⠸⠀⠀⠀⠀⢀⠎⠀⠀⠀⠀⠀⠀⠀⢰⣕⢿⣿⢿⢯⣿⣿⣿⣿⣮⡯⡷⣎⣻⣿⣿⣿⣿⣿⣿⣽⣿⣿⣫⡯⣧
⠈⢿⢿⣿⣿⣿⣿⠇⡟⢀⠀⢈⣹⡆⣸⡯⢻⣌⠷⢶⣀⡶⠛⠀⠀⠀⠀⠀⢀⡎⠀⠀⠀⠀⠀⢀⣠⣲⡿⣗⣿⣿⣽⣗⣿⣿⣿⣿⣿⣿⡫⣿⣿⣿⣿⣿⣿⣿⣗⣿⣿⣿⡷⣪⣿
⠀⠀⠛⣿⣿⣿⣿⢵⣽⣟⠦⠞⠁⡊⡪⣿⢨⡿⣯⣳⣭⣤⡀⠀⢠⠀⠀⠀⡘⠀⠀⠀⢀⣤⣾⡿⢋⣥⢾⢷⣷⢿⣇⢿⣏⣿⣿⣿⣿⣯⡿⣯⣺⣿⣿⣿⣵⣿⣿⣿⣿⣿⡯⡫⡎
⠀⠀⠀⠈⢿⣿⣿⡟⣿⣧⣿⣬⠠⢀⠡⢣⣼⡧⠊⠻⣝⣿⣿⢆⢸⠀⠀⢰⠁⢀⣠⣾⡿⠟⣡⠔⠋⠔⡀⡼⣟⣾⣽⣄⣿⣝⣿⣿⣿⣷⣿⣿⢻⣎⣿⣽⣿⣿⡿⣿⣿⣿⡯⣻⠇
*/