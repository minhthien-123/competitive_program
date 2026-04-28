#include <bits/stdc++.h>
#define ull unsigned long long

std::string s, s1, a;
ull move = 0, tmp;

int main()
{
    getline(std::cin, s);
    getline(std::cin, a);

    s1 = s;

    //std::cout << s << "\n" << a << "\n";

    for (ull i = 0; i < a.length(); i++)
        if (a[i] == 'R')
            move++;
        else
            move--;
    for (ull i = 0; i < s.length(); i++)
    {
        tmp = (i + move) % s.length();
        s1[tmp] = s[i];
    }

    std::cout << s1;
}