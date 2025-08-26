#include <bits/stdc++.h>
#define task "treat"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;

int n;
int a[maxn + 7];
std::stack<int> st;
int num[maxn + 7], low[maxn + 7], timer;
bool inStack[maxn + 7];
int comp[maxn + 7], sz[maxn + 7], cnt;
int ans[maxn + 7];

void tarjan(int u)
{
    num[u] = low[u] = ++timer;
    st.push(u);
    inStack[u] = true;
    int v = a[u];
    if (!num[v])
    {
        tarjan(v);
        low[u] = std::min(low[u], low[v]);
    }
    else
    {
        low[u] = std::min(low[u], low[v]);
    }

    if (low[u] == num[u])
    {
        cnt++;
        int v, d = 0;
        do
        {
            v = st.top();
            st.pop();
            inStack[v] = true;
            comp[v] = cnt;
            d++;
        } while (u != v);
        sz[cnt] = d;
    }
}

int get(int u)
{
    if (ans[u])
    {
        return ans[u];
    }

    return ans[u] = get(a[u]) + 1;
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }

    for (int i = 1; i <= n; i++)
    {
        if (!num[i])
        {
            tarjan(i);
        }
    }

    for (int u = 1; u <= n; u++)
    {
        int c = comp[u];
        if (sz[c] > 1 || a[u] == u)
        {
            ans[u] = sz[c];
        }
    }

    for (int u = 1; u <= n; u++)
    {
        if (!ans[u])
        {
            ans[u] = get(u);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        std::cout << ans[i] << "\n";
    }

    return 0;
}
