#include <bits/stdc++.h>
#define task "pt"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e15;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

struct pt
{
    int val, a, b;
};

int n, k;
std::vector<pt> v, ans;
std::vector<int> s;
bool check;

bool cmp(pt a, pt b)
{
    return a.val > b.val;
}

std::vector<pt> init(int n)
{
    std::vector<pt> res;
    for (int a = 0, x = 1; x <= n; a++, x *= 2)
    {
        for (int b = 0, y = 1; x * y <= n; b++, y *= 3)
        {
            res.pb({x * y, a, b});
        }
    }
    std::sort(res.begin(), res.end(), cmp);
    return res;
}

void solve(int pos, int sum)
{
    if (check && sum < 0)
    {
        return;
    }
    if (sum == 0)
    {
        check = true;
        return;
    }

    if (pos < s.size() && s[pos] < sum)
    {
        return;
    }

    for (int i = pos; i < v.size() && !check; i++)
    {
        if (v[i].val > sum)
        {
            continue;
        }
        bool flag = true;
        for (auto j : ans)
        {
            if ((j.a <= v[i].a && j.b <= v[i].b) || (v[i].a <= j.a && v[i].b <= j.b))
            {
                flag = false;
                break;
            }
        }
        if (!flag)
        {
            continue;
        }
        ans.pb(v[i]);
        solve(i + 1, sum - v[i].val);
        if (check)
        {
            return;
        }
        ans.pop_back();
    }
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task ".inp", "r"))
    {
        std::freopen(task ".inp", "r", stdin);
        std::freopen(task ".out", "w", stdout);
    }

    std::cin >> k;
    while (k--)
    {
        std::cin >> n;
        v = init(n);
        s.resize(v.size() + 1, 0);
        for (int i = v.size() - 1; i >= 0; i--)
        {
            s[i] = s[i + 1] + v[i].val;
        }
        ans.clear();
        check = false;
        solve(0, n);
        std::cout << ans.size() << " ";
        for (auto i : ans)
        {
            std::cout << i.val << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
