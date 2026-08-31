#include <bits/stdc++.h>
#define task "pt"
#define int long long
#define pb push_back
using namespace std;

const int maxn = 1e15;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

int n, k;

struct pt
{
    int val, a, b;

};

vector<pt> v, ans;
vector<int> s, res;
bool check;

bool cmp(pt a, pt b)
{
    return a.val > b.val;
}

void init()
{
    for (int a = 0, x = 1; x <= maxn; a++, x *= 2)
    {
        for (int b = 0, y = 1; x * y <= maxn; b++, y *= 3)
        {
            v.pb({x * y, a, b});
        }
    }
    sort(v.begin(), v.end(), cmp);

    s.resize(v.size() + 1);
    s[v.size()] = 0;
    for (int i = v.size() - 1; i >= 0; i--)
    {
        s[i] = s[i + 1] + v[i].val;
    }
}

bool check1(int a, int b)
{
    auto it = std::lower_bound(ans.begin(), ans.end(), pt{0, a, 0});
    int pos = it - ans.begin();
    for (int i = pos; i < ans.size(); i++)
    {
        if (ans[i].b >= b)
        {
            return true;
        }
    }
}

bool check2(int a, int b)
{
    auto it = std::upper_bound(ans.begin(), ans.end(), pt{0, a, 0});
    for (int i = 0; i < it - ans.begin(); i++)
    {
        if (ans[i].b <= b)
        {
            return true;
        }
    }
}

void solve(int pos, int sum)
{
    if (check || sum < 0)
    {
        return;
    }

    if (pos < s.size() && s[pos] < sum)
    {
        return;
    }

    if (sum == 0)
    {
        check = true;
        return;
    }

    for (int i = pos; i < v.size() && !check; i++)
    {
        if (v[i].val > sum)
        {
            continue;
        }

        if (check1(v[i].a, v[i].b))
        {
            continue;
        }
        if (check2(v[i].a, v[i].b))
        {
            continue;
        }

        auto tmp = std::upper_bound(ans.begin(), ans.end(), v[i]);
        ans.insert(tmp, v[i]);
        res.pb(v[i].val);
        solve(i + 1, sum - v[i].val);
        if (check)
        {
            return;
        }
        res.pop_back();
        ans.erase(std::lower_bound(ans.begin(), ans.end(), v[i]));
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    init();

    // cout << v.size() << "\n";
    // for (auto i : v)
    // {
    //     cout << i.val << " " << i.a << " " << i.b << "\n";
    // }

    cin >> k;
    while (k--)
    {
        cin >> n;
        int l = 0;
        while (l < v.size() && v[l].val > n)
        {
            l++;
        }
        check = false;
        ans.clear();
        res.clear();
        solve(l, n);

        cout << ans.size() << " ";
        for (auto i : res)
        {
            cout << i << " ";
        }
        cout << "\n";
    }

    return 0;
}
