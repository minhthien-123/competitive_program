#include <cstdio>
#include <cmath>
#include <math.h>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <list>
#define fi first
#define se second
#define PB push_back
#define MP make_pair
#define ep 0.00001
#define oo 111111111
#define mod 1000000007
#define TR(c, it) for (typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define rep(i, n) for (int i = 0; i < n; i++)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
// #define g 9.81
double const PI = 4 * atan(1.0);

using namespace std;

typedef pair<int, int> II;
typedef vector<int> VI;
typedef vector<II> VII;
typedef vector<VI> VVI;
typedef vector<VII> VVII;
typedef long long ll;

void OPEN()
{
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
}
// Dinic

#define maxn 50011
#define maxe 150111

struct HopcroftKarp
{
    int nx, ny, E, adj[maxe], next[maxe], last[maxn],
        matx[maxn], maty[maxn], que[maxn], level[maxn], run[maxn];

    void init(int _nx, int _ny)
    {
        nx = _nx;
        ny = _ny;
        E = 0;
        FOR(i, 1, nx)
        matx[i] = -1,
        last[i] = -1;
        FOR(i, 1, ny)
        maty[i] = -1;
    }

    void add(int x, int y)
    {
        adj[E] = y;
        next[E] = last[x];
        last[x] = E++;
    }

    bool bfs()
    {
        bool found = false;
        int size = 0;
        FOR(x, 1, nx)
        {
            if (matx[x] != -1)
                level[x] = -1;
            else
            {
                level[x] = 0;
                que[size++] = x;
            }
        }
        rep(i, size)
        {
            for (int x = que[i], e = last[x]; e != -1; e = next[e])
            {
                int y = adj[e];
                if (maty[y] == -1)
                    found = true;
                else if (level[maty[y]] == -1)
                {
                    level[maty[y]] = level[x] + 1;
                    que[size++] = maty[y];
                }
            }
        }

        return found;
    }

    int dfs(int x)
    {
        for (int &e = run[x]; e != -1; e = next[e])
        {
            int y = adj[e];
            if (maty[y] == -1 || (level[maty[y]] == level[x] + 1 && dfs(maty[y])))
            {
                maty[y] = x;
                matx[x] = y;
                return 1;
            }
        }
        return 0;
    }

    int maxMatching()
    {
        int total = 0;
        while (bfs())
        {
            FOR(x, 1, nx)
            run[x] = last[x];
            FOR(x, 1, nx)
            if (matx[x] == -1) total += dfs(x);
        }
        return total;
    }

} hopkarp;

int main()
{
    // OPEN();
    int n, m, x, y;
    scanf("%d %d", &n, &m);
    hopkarp.init(n, m);
    while (scanf("%d %d", &x, &y) > 0)
    {
        hopkarp.add(x, y);
    }
    printf("%d\n", hopkarp.maxMatching());
    FOR(x, 1, n)
    {
        y = hopkarp.matx[x];
        if (y != -1)
            printf("%d %d\n", x, y);
    }
}