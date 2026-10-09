#include "crocodilelib.h"

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int solve(int n, const vector<int> &u, const vector<int> &v, const vector<int> &l, const vector<int> &p)
{
    std::vector<std::vector<std::pair<int, int>>> adj(n);
    int m = (int)u.size();
    for (int i = 0; i < m; i++)
    {
        adj[u[i]].push_back({v[i], l[i]});
        adj[v[i]].push_back({u[i], l[i]});
    }

    std::vector<int> d1(n, INF), d2(n, INF);
    std::vector<bool> vis(n);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

    for (auto x : p)
    {
        d1[x] = 0;
        d2[x] = 0;
        pq.push({0, x});
    }

    while (!pq.empty())
    {
        auto [d, node_u] = pq.top();
        pq.pop();

        if (vis[node_u])
        {
            continue;
        }
        vis[node_u] = true;

        if (node_u == 0)
        {
            break;
        }

        for (auto &e : adj[node_u])
        {
            int node_v = e.first;
            int w = e.second;

            if (vis[node_v])
            {
                continue;
            }

            int new_dist = d2[node_u] + w;

            if (new_dist < d1[node_v])
            {
                d2[node_v] = d1[node_v];
                d1[node_v] = new_dist;

                if (d2[node_v] != INF)
                {
                    pq.push({d2[node_v], node_v});
                }
            }
            else if (new_dist < d2[node_v])
            {
                d2[node_v] = new_dist;
                pq.push({d2[node_v], node_v});
            }
        }
    }

    return (int)d2[0];
}
