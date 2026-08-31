#include <bits/stdc++.h>
#define task "edit"
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

int n;
std::string s1, s2, type;
int t1, t2, t3;

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    if (std::fopen(task ".out", "r"))
    {
        std::freopen(task ".out", "r", stdin);
        std::freopen(task ".chk", "w", stdout);
    }

    std::ifstream inp("edit.inp");

    std::cin >> n;
    inp >> s1 >> s2;
    inp >> t1 >> t2 >> t3;

    std::string s;
    int cost = 0;

    while (std::cin >> type)
    {
        int pos;
        char c;
        std::cin >> pos;
        if (type != "DEL")
        {
            std::cin >> c;
        }

        if (type == "DEL")
        {
            for (int i = 1; i <= (int)s1.size(); i++)
            {
                if (i != pos)
                {
                    s += s1[i - 1];
                }
            }
            cost += t2;
        }
        else if (type == "REP")
        {
            for (int i = 1; i <= (int)s1.size(); i++)
            {
                if (i == pos)
                {
                    s += c;
                }
                else
                {
                    s += s1[i - 1];
                }
            }
            cost += t3;
        }
        else if (type == "INS")
        {
            for (int i = 1; i <= (int)s1.size(); i++)
            {
                if (i == pos)
                {
                    s += c;
                }
                s += s1[i - 1];
            }
            cost += t1;
        }
        s1 = s;
        s.clear();
    }

    std::cout << cost << " " << s1 << " " << s2;

    return 0;
}
