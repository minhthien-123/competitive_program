#include <bits/stdc++.h>

const int maxn = 1e5 + 7;
int n, k;
int a[maxn];
std::map<int, int> m;

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    //std::freopen("seqk.inp", "r", stdin);
    //std::freopen("seqk.out", "w", stdout);

    std::cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        m[a[i]] = i;
    }

    for (int i = 1; i <= n; i++)
    {
        if (m[a[i]] && m[a[i] + k] && m[a[i]] != m[a[i] + k])
        {
            std::cout << m[a[i]] << " " << m[a[i] + k];
            return 0;
        }
        if (m[a[i]] && m[a[i] - k] && m[a[i]]!= m[a[i] - k])
        {
            std::cout << m[a[i]] << " " << m[a[i] - k];
            return 0;
        }
    }

    std::cout << 0;
}
