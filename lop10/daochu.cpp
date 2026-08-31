#include <bits/stdc++.h>
#define task "daochu"
#define int long long

std::string s;

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> s;

    std::sort(s.begin(), s.end());
    std::vector<std::string> v;

    do {
        v.push_back(s);
    } while (std::next_permutation(s.begin(), s.end()));

    std::cout << v.size() << "\n";
    for (const auto& str : v)
    {
        std::cout << str << "\n";
    }

    return 0;
}
