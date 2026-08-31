#include <bits/stdc++.h>
#define task "primeprx"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

bool isprime(int x) {
    if (x < 2) return false;
    for (int i = 2; i <= sqrt(x); i++)
        if (x % i == 0)
            return false;
    return true;
}

int solve(int n) {
    std::queue<std::string> q;
    std::set<std::string> vis;

    q.push(std::to_string(n));
    vis.insert(std::to_string(n));

    while (q.size()) {
        std::string t = q.front();
        q.pop();

        int x = std::stoll(t);

        if (isprime(x))
            return x;

        for (char i = '0'; i <= '9'; ++i) {
            std::string nx = t + i;
            if (vis.find(nx) == vis.end()) {
                q.push(nx);
                vis.insert(nx);
            }
        }
    }

    return -1;
}

int n;

signed main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    //std::freopen(task".inp", "r", stdin);
    //std::freopen(task".out", "w", stdout);

    std::cin >> n;
    std::cout << solve(n);

    return 0;
}
