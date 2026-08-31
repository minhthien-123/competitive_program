#include <bits/stdc++.h>
#define task "c"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e6;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

int n, m;
int a[maxn + 7], b[maxn + 7];
int sumA = 0, sumB = 0;
int dpA[maxn + 7], idA[maxn + 7], sA[maxn + 7];
int dpB[maxn + 7], idB[maxn + 7], sB[maxn + 7];

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

    std::cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        sumA += a[i];
    }
    for (int j = 0; j < m; j++)
    {
        std::cin >> b[j];
        sumB += b[j];
    }

    int s = std::max(sumA, sumB);

    dpA[0] = 1;
    idA[0] = -1;
    sA[0] = -1;

    for (int i = 0; i < n; i++)
    {
        for (int j = s; j >= a[i]; j--)
        {
            if (!dpA[j] && dpA[j - a[i]])
            {
                dpA[j] = 1;
                idA[j] = i;
                sA[j] = j - a[i];
            }
        }
    }

    dpB[0] = 1;
    idB[0] = -1;
    sB[0] = -1;

    for (int i = 0; i < m; i++)
    {
        for (int j = s; j >= b[i]; j--)
        {
            if (!dpB[j] && dpB[j - b[i]])
            {
                dpB[j] = 1;
                idB[j] = i;
                sB[j] = j - b[i];
            }
        }
    }

    int check = -1;
    for (int i = 1; i <= s; i++)
    {
        if (dpA[i] && dpB[i])
        {
            check = i;
            break;
        }
    }

    if (check == -1)
    {
        std::cout << "NO\n";
        return 0;
    }

    std::vector<int> ansA, ansB;
    int cur = check;
    while (cur > 0)
    {
        int idx = idA[cur];
        if (idx < 0)
        {
            break;
        }
        ansA.push_back(idx);
        cur = sA[cur];
    }
    std::reverse(ansA.begin(), ansA.end());

    cur = check;
    while (cur > 0)
    {
        int idx = idB[cur];
        if (idx < 0)
        {
            break;
        }
        ansB.push_back(idx);
        cur = sB[cur];
    }
    std::reverse(ansB.begin(), ansB.end());

    if (ansA.empty() || ansB.empty())
    {
        std::cout << "NO\n";
        return 0;
    }

    std::cout << "YES\n";
    std::cout << ansA.size() << '\n';
    for (int i = 0; i < ansA.size(); ++i)
    {
        std::cout << ansA[i] << " ";
    }
    std::cout << '\n';
    std::cout << ansB.size() << '\n';
    for (int i = 0; i < ansB.size(); ++i)
    {
        std::cout << ansB[i] << " ";
    }
    std::cout << '\n';

    return 0;
}
