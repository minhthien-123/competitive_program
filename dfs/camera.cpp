#include <bits/stdc++.h>
#define task "camera"
#define ll long long

const int maxn = 1e5 + 7;

int n;
int a[maxn], w[maxn], e[maxn], E[maxn], W[maxn];
int e1[maxn], w1[maxn], E1[maxn], W1[maxn];
char s[maxn];
std::deque<int> dq;

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];
    for (int i = 1; i <= n; i++)
        std::cin >> s[i];

    for (int i = n; i >= 1; i--)
    {
        e[i] = dq.size();
        while (dq.size() && a[dq.back()] < a[i])
            dq.pop_back();
        dq.push_back(i);
    }

    dq.clear();

    for (int i = 1; i <= n; i++)
    {
        w[i] = dq.size();
        while (dq.size() && a[dq.back()] < a[i])
            dq.pop_back();
        dq.push_back(i);
    }

    for (int i = 1; i <= n; i++)
        if (s[i] == 'W')
            std::cout << w[i] << " ";
        else
            std::cout << e[i] << " ";

    /*std::cout << "\n";
    for (int i = 1; i <= n; i++)
        std::cout << e[i] << " ";
    std::cout << "\n";
    for (int i = 1; i <= n; i++)
        std::cout << w[i] << " ";*/

    return 0;
}
