const int INF = 1e9;
const int MAXN = 2e6 + 5;

int n;
int D[MAXN], vis[MAXN];
vector<pair<int, int>> g[MAXN];
deque<int> dq;

void BFS_01(int s)
{
    for (int i = 1; i <= n; i++)
    {
        D[i] = INF;
        vis[i] = 0;
    }
    D[s] = 0;
    dq.push_front(s);
    while (!dq.empty())
    {
        int u = dq.front();
        dq.pop_front();
        if (vis[u])
            continue;
        vis[u] = 1;
        for (auto v : g[u])
        {
            if (D[v.first] > D[u] + v.second)
            {
                D[v.first] = D[u] + v.second;
                if (v.second == 1)
                    dq.push_back(v.first);
                else
                    dq.push_front(v.first);
            }
        }
    }
}