#include <bits/stdc++.h>
#define task "sp01"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

std::string st;
std::stack<int> s;
int beg, en, ans = INT_MIN;

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".ans", "w", stdout);
    }

    std::cin >> st;
    s.push(-1);

    for (int i = 0; i < st.size(); i++){
        if (st[i] == '0') s.push(i);
        else{
            s.pop();
            if (s.size() > 0){
                if (i - s.top() > ans){
                    ans = i - s.top();
                    beg = s.top() + 2;
                    en  = i + 1;
                }
            }
            else s.push(i);
        }
    }

    if (ans == INT_MIN) ans = 0;
    std::cout << ans << "\n";

    return 0;
}
