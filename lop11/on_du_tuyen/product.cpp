#include <bits/stdc++.h>
#define task "product"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;
const int inf = 1e18;
const int mod = 123456789;
const int inv = (mod + 1) / 2;

int k, n;
int a[maxn + 7];
std::vector<int> P, N;

int mul(int a, int b)
{
    int A = a % mod;
    if (A < 0)
    {
        A += mod;
    }
    int B = b % mod;
    if (B < 0)
    {
        B += mod;
    }
    return (A * B) % mod;
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    if (std::fopen(task ".inp", "r"))
    {
        std::freopen(task ".inp", "r", stdin);
        std::freopen(task ".out", "w", stdout);
    }

    int t;
    std::cin >> t;
    while (t--)
    {
        std::cin >> n >> k;
        N.clear();
        P.clear();
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            std::cin >> a[i];
            if (a[i] < 0)
            {
                N.pb(a[i]);
            }
            else if (a[i] > 0)
            {
                P.pb(a[i]);
            }
            else
            {
                cnt++;
            }
        }

        std::sort(N.begin(), N.end());
        std::sort(P.begin(), P.end(), std::greater<int>());

        if (P.empty() && k % 2 == 1)
        {
            if (cnt > 0)
            {
                std::cout << 0 << "\n";
            }
            else
            {
                int prod = 1;
                for (int i = 0; i < k; i++)
                {
                    prod = mul(prod, N[N.size() - 1 - i]);
                }
                std::cout << prod << "\n";
            }
            continue;
        }

        int prod = 1;

        if (k % 2 == 1)
        {
            prod = mul(prod, P[0]);
            P.erase(P.begin());
            k--;
        }

        int posP = 0, posN = 0;
        while (k > 0)
        {
            int ProdP;
            if (posP + 1 < P.size())
            {
                ProdP = P[posP] * P[posP + 1];
            }
            else
            {
                ProdP = -inf;
            }

            int ProdN;
            if (posN + 1 < N.size())
            {
                ProdN = N[posN] * N[posN + 1];
            }
            else
            {
                ProdN = -inf;
            }

            if (ProdP == -inf && ProdN == -inf)
            {
                if (cnt > 0)
                {
                    prod = 0;
                }
                break;
            }

            if (ProdP > ProdN)
            {
                prod = mul(prod, P[posP]);
                prod = mul(prod, P[posP + 1]);
                posP += 2;
            }
            else
            {
                prod = mul(prod, N[posN]);
                prod = mul(prod, N[posN + 1]);
                posN += 2;
            }

            k -= 2;
        }

        std::cout << prod << "\n";
    }

    return 0;
}
