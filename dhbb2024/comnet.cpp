#include <bits/stdc++.h>

struct Edge {
    int u, v, cost;

    Edge(int _u, int _v, int _cost) : u(_u), v(_v), cost(_cost) {}

    bool operator<(const Edge& other) const {
        return cost < other.cost;
    }
};

class DS {
private:
    std::vector<int> p, rank;

public:
    DS(int n) {
        p.resize(n);
        rank.resize(n, 1);
        for (int i = 0; i < n; ++i)
            p[i] = i;
    }

    int find(int u) {
        if (p[u] != u)
            p[u] = find(p[u]);
        return p[u];
    }

    bool us(int u, int v) {
        int root_u = find(u);
        int root_v = find(v);

        if (root_u != root_v) {
            if (rank[root_u] > rank[root_v])
                p[root_v] = root_u;
            else if (rank[root_u] < rank[root_v])
                p[root_u] = root_v;
            else {
                p[root_v] = root_u;
                rank[root_u]++;
            }
            return true;
        }
        return false;
    }
};

int mcost(int n, std::vector<Edge>& edges) {
    std::sort(edges.begin(), edges.end());

    DS ds(n);
    int min_cost = 0;
    int edges_used = 0;

    for (Edge& edge : edges) {
        if (ds.us(edge.u, edge.v)) {
            min_cost += edge.cost;
            edges_used++;
            if (edges_used == n - 1)
                break;
        }
    }

    return min_cost;
}

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<Edge> edges;

    for (int i = 0; i < m; ++i) {
        int u, v, cost;
        std::cin >> u >> v >> cost;
        edges.push_back(Edge(u - 1, v - 1, cost));
    }

    int res = mcost(n, edges);
    std::cout << res;

    return 0;
}
