#include <bits/stdc++.h>

std::string s, a, b;
int d = 0, i, x, y;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    std::freopen("APEASY.inp", "r", stdin);
    std::freopen("APEASY.out", "w", stdout);

    std::cin >> s;
    a = "";
    b = "";
    i = 0;
    while (s[i] != '+' && s[i] != '-'){
        a += s[i];
        i++;
    }
    //std::cout << a;
    i = s.size() - 1;
    while (s[i] != '-' && s[i] != '+'){
        b = s[i] + b;
        i--;
    }
    //std::cout << " " << b << "\n";
    x = stoi(a);
    y = stoi(b);
    //std::cout << x << " " << y << "\n";


    for (i = 0; i <= s.size() - 1; i++)
        if (s[i] == '-')
            d++;

    //std::cout << d << "\n";

    if (d % 2 == 0)
        std::cout << x + y;
    else
        std::cout << x - y;

    return 0;
}