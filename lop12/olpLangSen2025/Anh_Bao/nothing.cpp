#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>
#define fi first
#define se second
// #define int long long
#define ll long long
#define ld double
#define mp make_pair
#define lg2 30
#define iii pair<int, ii>
#define iiii pair<ii, ii>
#define base 29
#define eps 1e-8
#define MASK(i) (1LL << (i))
#define BIT(S, i) (((S) >> (i)) & 1)
int dx[] = {0LL, 0LL, 1, -1, 1, 1, -1, -1};
int dy[] = {1, -1, 0LL, 0LL, 1, -1, 1, -1};
const int maxn = 4e5 + 5;
const int mod = 1e9 + 7;
int n, c[maxn];
vector<int> a[maxn];
int ans = 0;
void dfs(int u, int cha)
{
    for (int v : a[u])
    {
        if (v == cha)
            continue;
        dfs(v, u);
        if (c[v] == 1)
        {
            c[v] ^= 1;
            c[u] ^= 1;
            ans++;
        }
    }
}
bool check()
{
    for (int i = 1; i <= n; i++)
    {
        if (c[i] == 1)
            return false;
    }
    return true;
}
void solve()
{
    ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
        a[i].clear();
    }
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(1, -1);
    if (check())
    {
        cout << ans;
    }
    else
        cout << -1;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#define task "task"
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << '\n';
    }
    cerr << endl
         << "TIME : " << clock() * 0.001 << "s" << endl;
}
