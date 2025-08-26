#include <bits/stdc++.h>
#define task
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

class bignum {
public:
    bignum() : digits("0"), flag(false) {}
    bignum(std::string num) {
        if (num[0] == '-') {
            flag = true;
            digits = num.substr(1);
        } else {
            flag = false;
            digits = num;
        }

        digits.erase(0, digits.find_first_not_of('0'));
        if (digits.empty()) digits = "0";
    }

    bignum operator*(bignum b) const {
        std::string x = digits;
        std::string y = b.digits;
        std::vector<int> ans(x.size() + y.size(), 0);

        for (int i = x.size() - 1; i >= 0; i--) {
            for (int j = y.size() - 1; j >= 0; j--) {
                int m = (x[i] - '0') * (y[j] - '0');
                int s = m + ans[i + j + 1];
                ans[i + j + 1] = s % 10;
                ans[i + j] += s / 10;
            }
        }

        std::string res;
        for (int num : ans) {
            if (!(res.empty() && num == 0)) {
                res.push_back(num + '0');
            }
        }
        if (res.empty()) res = "0";
        return bignum((flag != b.flag ? "-" : "") + res);
    }

    bool operator<(const bignum& b) const {
        if (flag != b.flag) return flag;
        if (digits.size() != b.digits.size()) {
            return (digits.size() < b.digits.size()) ^ flag;
        }
        return (digits < b.digits) ^ flag;
    }

    bool operator==(const bignum& b) const {
        return (digits == b.digits && flag == b.flag);
    }

    std::string str() const {
        return (flag ? "-" : "") + digits;
    }

private:
    std::string digits;
    bool flag;
};

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    //std::freopen(task".inp", "r", stdin);
    //std::freopen(task".out", "w", stdout);

    int t;
    std::cin >> t;

    while (t--) {
        std::string a, b, c, d;
        std::cin >> a >> b >> c >> d;
        bignum x(a), y(b), z(c), t(d);

        x = x * t;
        z = z * y;

        if (x < z)
            std::cout << -1;
        else if (x == z)
            std::cout << 0;
        else
            std::cout << 1;
        std::cout << "\n";
    }

    return 0;
}

