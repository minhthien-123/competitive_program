#include <bits/stdc++.h>
using namespace std;
bool M1;
#define PI 3.14159265358979323846
#define sz(a) (int)a.size()
#define all(x) x.begin(), x.end()
#define ii pair<int, int>
#define iii pair<int, ii>
#define iv pair<ii, ii>
#define int long long
#define se second
#define fi first
#define ffi fi.fi
#define sfi se.fi
#define sse se.se
#define fse fi.se
#define lt(i, c, d) for (int i = c; i <= d; ++i)
#define fl(i, c, d) for (int i = d; i >= c; --i)
#define pb push_back
#define emb emplace_back
#define emf emplace_front
#define em emplace
#define look_memory cerr << abs(&M2 - &M1) / 1024.0 / 1024 << '\n'
#define look_time cerr << "TIME : " << clock() * 0.001 << "s" << '\n'
const int N = 1e6 + 5, lg = 30, mod = 1e9 + 7;
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
int Rand(int u, int v)
{
    return u + rd() % (v - u + 1);
}
int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[] = {0, -1, 0, 1, 1, -1, 1, -1};
int node;
ii b[N];
bool M2;
void solve()
{
    cin >> node;
    for (int i = 1; i <= node; ++i)
        cin >> b[i].fi >> b[i].se;
    vector<ii> res;
    int val = 0, ans = 0;
    for (int i = 1; i <= node; ++i)
    {
        b[i].se += b[i].fi - 1;
        val = 0;
        ii z = make_pair(b[i].fi, -1);
        auto it = upper_bound(all(res), z);
        if (res.empty())
        {
            res.pb({b[i].fi, b[i].se});
            val = b[i].se - b[i].fi + 1;
        }
        else
        {
            auto it1 = it;
            if (it1 != res.begin())
            {
                --it1;

                int u = it - res.begin();
                val += b[i].se - b[i].fi + 1;
                for (int x = 0; x < u; ++x)
                    val += res[x].se - res[x].fi + 1;
                bool ok = true;
                if (it1->se + 1 >= b[i].fi)
                {
                    val -= max(0LL, it1->se - b[i].fi + 1);
                    (*it1) = {min(it1->fi, b[i].fi), max(it1->se, b[i].se)};
                    ok = false;
                    b[i] = *it1;
                }
                {
                    vector<ii> xoa;
                    while (it != res.end())
                    {
                        if (it->se <= b[i].se)
                            xoa.emb(*it);
                        else
                        {
                            (*it) = {max(it->fi, b[i].se + 1), it->se};
                            break;
                        }
                        it++;
                    }

                    for (auto x : xoa)
                    {
                        auto vv = lower_bound(all(res), x);
                        res.erase(vv);
                    }
                    if (ok)
                        res.insert(it1 + 1, b[i]);
                }
            }
            else
            {
                ++it;
                vector<ii> xoa;
                while (it != res.end())
                {
                    if (it->se <= b[i].se)
                        xoa.emb(*it);
                    else
                    {
                        (*it) = {max(it->fi, b[i].se + 1), it->se};
                        break;
                    }
                    it++;
                }
                for (auto x : xoa)
                {
                    auto vv = lower_bound(all(res), x);
                    res.erase(vv);
                }
                res.insert(res.begin(), b[i]);
            }
        }
        ans = max(ans, val);
    }

    cout << ans;
}
main()
{
    srand(time(0));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#define task "aws"
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int t = 1;
    //   cin >> t;
    while (t--)
    {
        solve();
        cout << '\n';
    }
    look_memory;
    look_time;
}