#include <bits/stdc++.h>
#define task "festival"
#include "festivallib.h"
#define __Thien_dep_trai__ signed main()
#define thiendeptrai true
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
using namespace std;
const int maxn = 205;
const ll INF = 1e18;
const int inf = 1e9;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;
const int lg = 20;
const int dx[] = {0, 1, 0, -1, -1, -1, 1, 1};
const int dy[] = {1, 0, -1, 0, -1, 1, -1, 1};

int n;
vector<int> need[maxn], adj[maxn + 7];
bool flag[maxn + 7], vis[maxn + 7];
int color[maxn + 7];
int dp[maxn + 7];

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
    return (x * y) % mod;
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

int dfs(int u)
{
    if (vis[u])
    {
        return dp[u];
    }
    vis[u] = true;
    int mx = 0;
    for (int v : adj[u])
    {
        mx = std::max(mx, dfs(v));
    }
    return dp[u] = mx + 1;
}

bool cmp(int a, int b)
{
    return dp[a] > dp[b];
}

vector<int> solveGenius(int N, int S, const vector<int> &U, const vector<int> &V)
{
    n = N;
    for (int i = 0; i < n; i++)
    {
        need[i].clear();
        adj[i].clear();
        flag[i] = false;
        color[i] = 0;
        vis[i] = false;
        dp[i] = 0;
    }

    for (int i = 0; i < U.size(); i++)
    {
        need[V[i]].pb(U[i]);
        adj[U[i]].pb(V[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }

    int cur = 1;
    int count = 0;
    while (thiendeptrai)
    {
        if (count >= n)
        {
            break;
        }
        std::vector<int> vec;

        for (int v = 0; v < n; v++)
        {
            if (!flag[v])
            {
                bool ok = true;

                for (int u : need[v])
                {
                    if (!flag[u])
                    {
                        ok = false;
                        break;
                    }
                }

                if (ok)
                {
                    vec.pb(v);
                }
            }
        }

        std::sort(all(vec), cmp);

        int cnt = 0;
        for (int i : vec)
        {
            if (cnt >= S)
            {
                break;
            }
            color[i] = cur;
            cnt++;
            flag[i] = true;
            count++;
        }

        cur++;
    }

    std::vector<int> res;
    for (int i = 0; i < n; i++)
    {
        res.pb(color[i]);
    }

    return res;
}

bool solveCitizen(const vector<int> &A, const vector<vector<int>> &history)
{
    int cur = 1;
    int wait = 0;

    for (int i = 0; i < history.size(); i++)
    {
        if (history[i].empty())
        {
            wait++;
        }
        else
        {
            cur++;
            wait = 0;
        }
    }

    int cnt = 0;
    for (int x : A)
    {
        if (x == cur)
        {
            cnt++;
        }
    }

    if (cnt == wait)
    {
        return true;
    }

    return false;
}