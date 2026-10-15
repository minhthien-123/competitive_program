#include <bits/stdc++.h>
#include "asktreelib.h"
#define task "asktreez"
#define __Thien_dep_trai__ signed main()
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

const int maxn = 5e3;

int dist[maxn + 7];
int par[maxn + 7];
std::vector<int> layers[maxn + 7];

int get_cost(std::vector<int> S, int n)
{
    std::vector<bool> used(n + 1, false);
    used[1] = true;
    int cnt = 0;

    for (int v : S)
    {
        int cur = v;
        while (!used[cur])
        {
            used[cur] = true;
            cnt++;
            cur = par[cur];
        }
    }
    return cnt;
}

void SOLVE(int n)
{
    for (int i = 0; i <= n; i++)
    {
        layers[i].clear();
        par[i] = 0;
    }

    layers[0].pb(1);

    for (int i = 2; i <= n; i++)
    {
        dist[i] = ASK({1, i});
        layers[dist[i]].pb(i);
    }

    for (int d = 1; d < n; d++)
    {
        if (layers[d].empty())
        {
            break;
        }

        std::vector<int> cand = layers[d - 1];

        for (int u : layers[d])
        {
            if (sz(cand) == 1)
            {
                par[u] = cand[0];
                ANSWER(u, cand[0]);
                continue;
            }

            int l = 0, r = sz(cand) - 1;

            while (l < r)
            {
                int mid = (l + r) / 2;

                std::vector<int> S;
                S.pb(1);
                for (int i = 0; i <= mid; i++)
                {
                    if (cand[i] != 1)
                    {
                        S.pb(cand[i]);
                    }
                }

                int cost_S = get_cost(S, n);

                std::vector<int> S_u = S;
                S_u.pb(u);
                int cost_Su = ASK(S_u);

                if (cost_Su == cost_S + 1)
                {
                    r = mid;
                }
                else
                {
                    l = mid + 1;
                }
            }

            par[u] = cand[l];
            ANSWER(u, cand[l]);
        }
    }
}