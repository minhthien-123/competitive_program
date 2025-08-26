#include <bits/stdc++.h>
#define task "bignum"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

std::string a, b;

std::string tong(){
    std::string result = "";
    int carry = 0;
    int sum;

    int len1 = a.size();
    int len2 = b.size();

    std::string n1 = a;
    std::string n2 = b;
    reverse(n1.begin(), n1.end());
    reverse(n2.begin(), n2.end());

    for (int i = 0; i < len1; i++) {
        int digit1 = n1[i] - '0';
        int digit2 = (i < len2) ? n2[i] - '0' : 0;
        sum = digit1 + digit2 + carry;
        carry = sum / 10;
        result += (sum % 10) + '0';
    }

    if (carry) {
        result += carry + '0';
    }

    reverse(result.begin(), result.end());
    return result;
}

std::string hieu() {
    std::string result = "";
    int borrow = 0;
    int diff;

    int len1 = a.size();
    int len2 = b.size();

    std::string n1 = a;
    std::string n2 = b;
    reverse(n1.begin(), n1.end());
    reverse(n2.begin(), n2.end());

    for (int i = 0; i < len1; i++) {
        int digit1 = n1[i] - '0';
        int digit2 = (i < len2) ? n2[i] - '0' : 0;
        diff = digit1 - digit2 - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result += diff + '0';
    }

    while (result.size() > 1 && result.back() == '0') {
        result.pop_back();
    }

    reverse(result.begin(), result.end());
    return result;
}

signed main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen(task".inp", "r", stdin);
    std::freopen(task".out", "w", stdout);
    
    std::cin >> a;
    std::cin >> b;
    
    std::cout << tong() << "\n";
    std::cout << hieu();
    
    return 0;
}
