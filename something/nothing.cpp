#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n))
        return 0;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Euler tour (tin,tout) and parent/depth by iterative DFS
    vector<int> parent(n + 1, 0), depth(n + 1, 0), tin(n + 1, 0), tout(n + 1, 0);
    int timer = 0;
    // iterative DFS: stack of (node, index next child to process)
    vector<pair<int, int>> st;
    st.reserve(n * 2);
    st.push_back({1, 0});
    parent[1] = 1;
    depth[1] = 0;
    while (!st.empty())
    {
        int u = st.back().first;
        int &idx = st.back().second;
        if (idx == 0)
        {
            tin[u] = ++timer;
        }
        if (idx < (int)adj[u].size())
        {
            int v = adj[u][idx++];
            if (v == parent[u])
                continue;
            parent[v] = u;
            depth[v] = depth[u] + 1;
            st.push_back({v, 0});
        }
        else
        {
            tout[u] = timer;
            st.pop_back();
        }
    }

    // binary lifting
    int LOG = 1;
    while ((1 << LOG) <= n)
        ++LOG;
    vector<vector<int>> up(LOG, vector<int>(n + 1));
    for (int v = 1; v <= n; ++v)
        up[0][v] = parent[v];
    for (int k = 1; k < LOG; ++k)
        for (int v = 1; v <= n; ++v)
            up[k][v] = up[k - 1][up[k - 1][v]];

    auto is_ancestor = [&](int a, int b) { // a ancestor of b ?
        return tin[a] <= tin[b] && tout[b] <= tout[a];
    };
    auto lca = [&](int a, int b)
    {
        if (is_ancestor(a, b))
            return a;
        if (is_ancestor(b, a))
            return b;
        for (int k = LOG - 1; k >= 0; --k)
        {
            int wa = up[k][a];
            if (!is_ancestor(wa, b))
                a = wa;
        }
        return up[0][a];
    };
    auto dist = [&](int a, int b)
    {
        int c = lca(a, b);
        return (ll)depth[a] + depth[b] - 2 * depth[c];
    };

    // For each i: build nodes = multiples of i, plus node 1 (root).
    // Sort by tin, unique, build virtual tree by stack and sum edge lengths.
    vector<ll> ans(n + 1, 0);
    vector<int> nodes;
    nodes.reserve(n);
    for (int i = 1; i <= n; ++i)
    {
        nodes.clear();
        for (int x = i; x <= n; x += i)
            nodes.push_back(x);
        // ensure root (1) is included so we connect to root paths
        nodes.push_back(1);

        // sort by tin and unique
        sort(nodes.begin(), nodes.end(), [&](int a, int b)
             { return tin[a] < tin[b]; });
        nodes.erase(unique(nodes.begin(), nodes.end()), nodes.end());

        // Build virtual tree on nodes (stack method)
        vector<int> stk;
        stk.reserve(nodes.size() + 5);
        ll total_len = 0;
        stk.push_back(nodes[0]);
        for (size_t idx = 1; idx < nodes.size(); ++idx)
        {
            int v = nodes[idx];
            int w = lca(v, stk.back());
            if (w == stk.back())
            {
                stk.push_back(v);
                continue;
            }
            // pop until we find place for w
            while (stk.size() >= 2 && depth[stk[stk.size() - 2]] >= depth[w])
            {
                // connect stk.back() with stk[stk.size()-2]
                total_len += dist(stk.back(), stk[stk.size() - 2]);
                stk.pop_back();
            }
            if (stk.back() != w)
            {
                // connect stk.back() with w
                total_len += dist(stk.back(), w);
                stk.pop_back();
                stk.push_back(w);
            }
            stk.push_back(v);
        }
        while (stk.size() >= 2)
        {
            total_len += dist(stk.back(), stk[stk.size() - 2]);
            stk.pop_back();
        }

        ans[i] = 2 * total_len; // go and return
    }

    // output
    for (int i = 1; i <= n; ++i)
        cout << ans[i] << '\n';
    return 0;
}
