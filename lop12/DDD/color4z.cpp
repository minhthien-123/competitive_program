#include <bits/stdc++.h>
#include "color4lib.h"
using namespace std;

namespace personA
{
    string Alice(int n, int m, const vector<pair<int, int>> &edges, const vector<int> &colors)
    {
        string bits(n, '0');
        for (int i = 0; i < n; i++)
        {
            if (colors[i] == 1 || colors[i] == 2)
            {
                bits[i] = '0';
            }
            else
            {
                bits[i] = '1';
            }
        }
        return bits;
    }
}

namespace personB
{
    const int maxn = 1e5 + 7;
    vector<int> adj[maxn];
    pair<int, int> opt[maxn];
    int ans[maxn];
    vector<int> history;

    bool dfs(int u, int c)
    {
        ans[u] = c;
        history.push_back(u);

        for (int v : adj[u])
        {
            if (ans[v] != 0)
            {
                if (ans[v] == ans[u])
                {
                    return false;
                }
            }
            else
            {
                if (opt[v].first == ans[u])
                {
                    if (!dfs(v, opt[v].second))
                    {
                        return false;
                    }
                }
                else if (opt[v].second == ans[u])
                {
                    if (!dfs(v, opt[v].first))
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    void reset()
    {
        for (int u : history)
        {
            ans[u] = 0;
        }
        history.clear();
    }

    void Bob(int n, int m, const vector<pair<int, int>> &edges, const string &bits)
    {
        for (int i = 1; i <= n; i++)
        {
            adj[i].clear();
            ans[i] = 0;
            if (bits[i - 1] == '0')
            {
                opt[i] = {1, 2};
            }
            else
            {
                opt[i] = {3, 4};
            }
        }

        for (auto e : edges)
        {
            int u = e.first;
            int v = e.second;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int i = 1; i <= n; i++)
        {
            if (ans[i] != 0)
            {
                continue;
            }

            history.clear();
            if (!dfs(i, opt[i].first))
            {
                reset();
                dfs(i, opt[i].second);
            }
        }

        for (int i = 1; i <= n; i++)
        {
            paint(i, ans[i]);
        }
    }
}
