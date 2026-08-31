#include <bits/stdc++.h>
#define task "dayso"
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

const int maxn = 5e4;
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

std::vector<int> adj[maxn + 7];
int n, q;
int a[maxn + 7];
int cntL[maxn + 7], cntR[maxn + 7];
int final_ans[maxn + 7];

struct MoAlgorithm
{
    int n, block_size;

    struct Query
    {
        int l, r, id, block, sign;
        bool operator<(const Query &other) const
        {
            if (block != other.block)
                return block < other.block;
            return (block & 1) ? (r < other.r) : (r > other.r);
        }
    };

    std::vector<Query> queries;

    MoAlgorithm(int n)
    {
        this->n = n;
        block_size = std::sqrt(n) + 1;
    }

    void add_query(int l, int r, int id, int sign)
    {
        queries.push_back({l, r, id, l / block_size, sign});
    }

    void solve()
    {
        std::sort(queries.begin(), queries.end());
        int cur_l = 1, cur_r = 0;
        int ans = 0;

        for (auto q : queries)
        {
            while (cur_l < q.l)
            {
                cur_l++;
                ans += cntR[a[cur_l]];
                cntL[a[cur_l]]++;
            }

            while (cur_l > q.l)
            {
                ans -= cntR[a[cur_l]];
                cntL[a[cur_l]]--;
                cur_l--;
            }

            while (cur_r < q.r)
            {
                cur_r++;
                ans += cntL[a[cur_r]];
                cntR[a[cur_r]]++;
            }

            while (cur_r > q.r)
            {
                ans -= cntL[a[cur_r]];
                cntR[a[cur_r]]--; 
                cur_r--;
            }

            final_ans[q.id] += q.sign * ans;
        }
    }
};

void solve()
{
    std::cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }

    MoAlgorithm mo(n);

    for (int i = 1; i <= q; i++)
    {
        int x, y, u, v;
        std::cin >> x >> y >> u >> v;

        mo.add_query(y, v, i, 1);
        mo.add_query(x - 1, v, i, -1);
        mo.add_query(y, u - 1, i, -1);
        mo.add_query(x - 1, u - 1, i, 1);
    }

    mo.solve();

    for (int i = 1; i <= q; i++)
    {
        std::cout << final_ans[i] << "\n";
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