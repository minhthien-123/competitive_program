#include <bits/stdc++.h>
#define ll long long

std::string s;
ll a = 0, b = 0;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    std::freopen("cnch4.inp", "r", stdin);
    std::freopen("cnch4.out", "w", stdout);

    getline(std::cin, s);

    for (ll i = 0; i <= s.size(); i++)
        if (s[i] >= '0' && s[i] <= '9')
            a++;
        else if (s[i] >= 'a' && s[i] <= 'z')
            b++;
        else if (s[i] >= 'A' && s[i] <= 'Z')
            b++;

    std::cout << b << " " << a;

    return 0;
}