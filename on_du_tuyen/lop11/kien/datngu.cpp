#include <bits/stdc++.h>
#define skibidi                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define file(tenfile)                         \
    if (fopen(tenfile ".inp", "r"))           \
    {                                         \
        freopen(tenfile ".inp", "r", stdin);  \
        freopen(tenfile ".out", "w", stdout); \
    }
#define all(x) x.begin(), x.end()
#define fi first
#define se second
#define ii pair<int, int>
#define iii pair<int, ii>
#define On(mask, pos) (mask | (1LL << pos))
#define Off(mask, pos) (mask ^ (1LL << pos))
#define endl "\n"
using namespace std;
const int N = 4e6 + 69;
const int BASE = 256;
const int MOD = 1e9 + 7;
int add(int a, int b)
{
    return (a + b) % MOD;
}
int sub(int a, int b)
{
    return ((a - b) % MOD + MOD) % MOD;
}
int mul(int a, int b)
{
    return ((a % MOD) * (b % MOD)) % MOD;
}
int t, n, a[N], e[N], weight[N];
struct fight
{
    int cntb;
    int T;
    int C;
    int weightT;
    int weightC;
};
vector<fight> cases;
bool cmp(fight a, fight b)
{
    if (a.cntb != b.cntb)
        return a.cntb < b.cntb;
    if (a.weightC != b.weightC)
        return a.weightC < b.weightC;
    if (a.weightT != b.weightT)
        return a.weightT < b.weightT;
    return a.C < b.C;
}
bool test(int mid)
{
    int cnt[8] = {0};
    cnt[7] = mid;
    for (int i = 1; i <= n; i++)
    {
        int target = e[i];
        bool found = 0;
        for (int j = 0; j < cases.size(); j++)
        {
            if (cases[j].weightC < target)
                continue;
            if (cnt[cases[j].T])
            {
                cnt[cases[j].T]--;
                cnt[cases[j].T ^ cases[j].C]++;
                found = 1;
                break;
            }
        }
        if (!found)
            return 0;
    }
    return 1;
}
void solve()
{
    cin >> n;
    cin >> a[1] >> a[2] >> a[3];
    int maxn = a[1] + a[2] + a[3];
    bool check = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> e[i];
        if (e[i] > maxn)
            check = 0;
    }
    if (!check)
    {
        cout << -1 << endl;
        return;
    }
    cases.clear();
    sort(e + 1, e + n + 1, greater<int>());
    for (int i = 0; i <= 7; i++)
        weight[i] = 0;
    for (int mask = 1; mask < (1 << 3); mask++)
    {
        for (int j = 1; j <= 3; j++)
        {
            if (mask & (1 << (j - 1)))
            {
                weight[mask] += a[j];
            }
        }
    }
    for (int T = 1; T <= 7; T++)
    {
        for (int C = 1; C <= 7; C++)
        {
            if ((T & C) == C)
            {
                cases.push_back({__builtin_popcount(C), T, C, weight[T], weight[C]});
            }
        }
    }
    sort(cases.begin(), cases.end(), cmp);
    int l = n / 3, r = n, ans = -1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (test(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << ans << endl;
}
main()
{
    skibidi;
    file("fight");
    cin >> t;
    while (t--)
        solve();
}
/*  I am the bone of my sword
    Steel is my body and fire is my blood
    I have created over a thousand blades
    Unknown to Death,
    Nor known to Life.
    Have withstood pain to create many weapons
    Yet, those hands will never hold anything
    So as I pray, unlimited blade works.
*/
