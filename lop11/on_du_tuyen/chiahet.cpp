#include <bits/stdc++.h>
#define task "chiahet"
#define ll long long

const int maxn = 1e6 + 7;

inline bool cmp(int x, int y){return x > y;}

int prod = 1, m, ans = 0, a[maxn], n;
std::string s;

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen(task".inp", "r", stdin);
    std::freopen(task".out", "w", stdout);

    std::cin >> s >> m;
    n = s.size();
    for (int i = 0; i < s.size(); i++)
        a[i + 1] = s[i] - '0';
    std::sort(a + 1, a + n + 1, cmp);

    if (m == 2 || m == 6){
        int i = n;
        while (a[i] % 2 != 0)
            i--;
        std::swap(a[i], a[n]);
    }

    for (int i = 1; i <= n; i++)
        std::cout << a[i];
    std::cout << "\n";

    std::cout << ans;

    return 0;
}
