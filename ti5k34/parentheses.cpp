#include <bits/stdc++.h>
#define task "parentheses"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    int n;
    std::cin >> n;
    for (int j = 0; j < n; j++){
        std::string st;
        std::stack<char> s;
        bool flag = true;

        std::cin >> st;
        for (int i = 0; i < st.size(); i++){
            if (st[i] == '(' || st[i] == '[' || st[i] == '{')
            {
                s.push(st[i]);
            }
            else
            {
                if (s.empty())
                {
                    flag = false;
                }
                else
                {
                    if (s.top() == '(' && st[i] == ')')
                    {
                        s.pop();
                    }
                    else if (s.top() == '[' && st[i] == ']')
                    {
                        s.pop();
                    }
                    else if (s.top() == '{' && st[i] == '}')
                    {
                        s.pop();
                    }
                    else
                    {
                        flag = false;
                    }
                }
            }
        }

        if (!s.empty()) flag = false;

        if (flag == false)
        {
            std::cout << "NO\n";
        }
        else
        {
            std::cout << "YES\n";
        }

        //flag = true;
    }

    return 0;
}
