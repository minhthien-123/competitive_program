#include <bits/stdc++.h>

long long xa1, ya1, xb1, yb1, xa2, ya2, xb2, yb2, xa3, ya3, xb3, yb3, s1, s2, s3;

int main(){
    std::ios_baseW::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    std::freopen("mrear.inp", "r", stdin);
    std::freopen("mrear.out", "w", stdout);

    std::cin >> xa1 >> ya1 >> xb1 >> yb1;
    std::cin >> xa2 >> ya2 >> xb2 >> yb2;
    std::cin >> xa3 >> ya3 >> xb3 >> yb3;

    s1 = abs(xa1 - xb1) * abs(ya1 - yb1);
    s2 = abs(xa2 - xb2) * abs(ya2 - yb2);
    s3 = abs(xa3 - xb3) * abs(ya3 - yb3);

    std::cout << std::min(s1, std::min(s2, s3));

    return 0;
}