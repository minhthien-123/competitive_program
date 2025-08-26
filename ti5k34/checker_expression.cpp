#include <bits/stdc++.h>
#define task "expression"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e2;
const int maxs = 3e4;
const int inf  = 1e18;

int n, s;
int a[maxn + 7];
int sum = 0;
std::string str;

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::ifstream input(task".inp");
    std::ifstream output(task".out");

    input >> n >> s;
    for (int i = 1; i <= n; i++)
    {
        input >> a[i];
    }
    input.close();
    output >> str;
    output.close();

    sum = a[1];
    for (int i = 2; i <= n; i++)
    {
        if (str[i - 2] == '+')
        {
            sum += a[i];
        }
        else
        {
            sum -= a[i];
        }
    }

    std::ofstream check(task".chk");
    if (sum == s)
    {
        check << "ACCEPTED";
    }
    else
    {
        check << "WRONG ANSWER";
    }

    return 0;
}
