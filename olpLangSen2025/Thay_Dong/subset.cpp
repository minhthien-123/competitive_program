#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>
#define fi first
#define se second
#define int long long
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
const int maxn = 2e5 + 5, mx = 1e9;
const int mod = 1e9 + 7;
int n, l, r, a[maxn], s[maxn];
namespace sub2
{
    bool check()
    {
        return n <= 40;
    }
    vector<ii> xly(vector<ii> &v)
    {
        vector<ii> bla;
        int hih = v.size();
        for (int mask = 1; mask < MASK(hih); mask++)
        {
            int cnt = 0;
            for (int j = 0; j < hih; j++)
            {
                if (BIT(mask, j))
                {
                    cnt += v[j].fi;
                }
            }
            bla.push_back({cnt, mask});
        }
        sort(bla.begin(), bla.end());
        return bla;
    }
    void solve()
    {
        vector<ii> vec1, vec2, xly1, xly2;
        int x = n / 2;
        for (int i = 1; i <= x; i++)
        {
            vec1.push_back({a[i], i});
        }
        for (int i = x + 1; i <= n; i++)
        {
            vec2.push_back({a[i], i});
        }
        xly1 = xly(vec1);
        xly2 = xly(vec2);
        vector<int> ans;
        for (ii x : xly1)
        {
            //  cout<<x.fi<<" ";
            if (x.fi >= l && x.fi <= r)
            {
                for (int i = 0; i < (int)vec1.size(); i++)
                {
                    if (BIT(x.se, i))
                    {
                        ans.push_back(vec1[i].se);
                    }
                }
                sort(ans.begin(), ans.end());
                cout << ans.size() << '\n';
                for (int x : ans)
                {
                    cout << x << " ";
                }
                return;
            }
        }
        for (ii x : xly2)
        {
            if (x.fi >= l && x.fi <= r)
            {
                for (int i = 0; i < (int)vec2.size(); i++)
                {
                    if (BIT(x.se, i))
                    {
                        ans.push_back(vec2[i].se);
                    }
                }
                sort(ans.begin(), ans.end());
                cout << ans.size() << '\n';
                for (int x : ans)
                {
                    cout << x << " ";
                }
                return;
            }
        }
        for (ii x : xly1)
        {
            int t = lower_bound(xly2.begin(), xly2.end(), mp(l - x.fi, 0LL)) - xly2.begin();
            if (t == (int)xly2.size())
                continue;
            if (x.fi + xly2[t].fi >= l && x.fi + xly2[t].fi <= r)
            {
                // cout<<x.fi<<" "<<x.se<<'\n';
                for (int i = 0; i < (int)vec1.size(); i++)
                {
                    if (BIT(x.se, i))
                    {
                        ans.push_back(vec1[i].se);
                    }
                }
                //   cout<<1<<'\n';
                for (int i = 0; i < (int)vec2.size(); i++)
                {
                    if (BIT(xly2[t].se, i))
                    {
                        ans.push_back(vec2[i].se);
                    }
                }

                sort(ans.begin(), ans.end());
                cout << ans.size() << "\n";
                for (int x : ans)
                {
                    cout << x << " ";
                }
                return;
            }
        }
    }
}
namespace sub3
{
    bool check()
    {
        bool ok = true;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] > 1e5 || l > 1e5 || r > 1e5)
                return false;
        }
        return n <= 80;
    }
    int dp[maxn];
    void solve()
    {
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = r; j >= a[i]; j--)
            {
                if (dp[j - a[i]] && !dp[j])
                {
                    dp[j] = i;
                    if (j >= l)
                    {
                        vector<int> ans;
                        while (j)
                        {
                            ans.push_back(dp[j]);
                            j -= a[dp[j]];
                        }
                        reverse(ans.begin(), ans.end());
                        cout << ans.size() << '\n';
                        for (int x : ans)
                        {
                            cout << x << " ";
                        }
                        return;
                    }
                }
            }
        }
    }
}
namespace sub4
{
    bool check()
    {
        for (int i = 1; i <= n; i++)
        {
            if (a[i] != a[1])
                return false;
        }
        return true;
    }
    void solve()
    {
        int x = 0;
        for (int i = 1; i <= n; i++)
        {
            x += a[i];
            if (x >= l)
            {
                cout << i << '\n';
                for (int j = 1; j <= i; j++)
                {
                    cout << j << " ";
                }
            }
        }
    }
}
namespace sub5
{
    bool check()
    {
        for (int i = 1; i <= n; i++)
        {
            if (a[i] != i)
                return false;
        }
        return true;
    }
    void solve()
    {
        vector<int> ans;
        for (int i = n; i >= 1; i--)
        {
            if (l >= i)
            {
                ans.push_back(i);
                l -= i;
            }
            if (!l)
                break;
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << '\n';
        for (int x : ans)
            cout << x << " ";
    }
}
namespace sub6
{
    bool check()
    {
        int mxx = 0, mn = 1e18;
        for (int i = 1; i <= n; i++)
        {
            mxx = max(mx, a[i]);
            mn = min(mn, a[i]);
        }
        return (r - l >= mxx - mn);
    }
    ii b[maxn];
    int pre[maxn];
    void solve()
    {
        for (int i = 1; i <= n; i++)
        {
            b[i] = {a[i], i};
        }
        sort(b + 1, b + n + 1);
        for (int i = 1; i <= n; i++)
        {
            pre[i] = pre[i - 1] + b[i].fi;
        }
        int j = 0;
        for (int i = 1; i <= n; i++)
        {
            while (j <= i && pre[i] - pre[j] > r)
                j++;
            if (pre[i] - pre[j] >= l)
            {
                vector<int> ans;
                for (int x = j + 1; x <= i; x++)
                {
                    ans.push_back(b[x].se);
                }
                sort(ans.begin(), ans.end());
                cout << ans.size() << '\n';
                for (int x : ans)
                    cout << x << " ";
                return;
            }
        }
        cout << -1;
    }
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
    cin >> n >> l >> r;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
        if (s[i] >= l && s[i] <= r)
        {
            cout << i << '\n';
            for (int j = 1; j <= i; j++)
            {
                cout << j << " ";
            }
            return 0;
        }
        if (a[i] >= l && a[i] <= r)
        {
            cout << 1 << '\n';
            cout << i;
            return 0;
        }
    }
    if (sub2::check())
    {
        sub2::solve();
    }
    else if (sub3::check())
    {
        sub3::solve();
    }
    else if (sub4::check())
    {
        sub4::solve();
    }
    else if (sub5::check())
    {
        sub5::solve();
    }
    else
        sub6::solve();
    cerr << endl
         << "TIME : " << clock() * 0.001 << "s" << endl;
}