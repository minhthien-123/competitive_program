#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;

typedef long long ll;

ll hash_func(vector<int>& arr1, vector<int>& arr2, ll p) {
    ll mul = 1;
    for (int i = 0; i < arr1.size(); i++) {
        mul = mul * arr1[i] % p;
    }
    for (int i = 0; i < arr2.size(); i++) {
        mul = mul * arr2[i] % p;
    }
    stringstream ss;
    ss << hex << mul;
    string hash_val = ss.str();
    ll sum = 0;
    for (int i = 0; i < hash_val.size(); i++) {
        char c = hash_val[i];
        int d;
        if (c >= '0' && c <= '9') {
            d = c - '0';
        } else if (c >= 'a' && c <= 'f') {
            d = c - 'a' + 10;
        } else if (c >= 'A' && c <= 'F') {
            d = c - 'A' + 10;
        } else {
            continue;
        }
        sum = (sum * 16 + d) % p;
    }
    return sum;
}

int main() {
    int n, m;
    ll p;
    cin >> n >> m;
    vector<int> arr1(n);
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }
    vector<int> arr2(m);
    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }
    cin >> p;
    ll hash_val = hash_func(arr1, arr2, p);
    cout << hash_val << endl;
    return 0;
}
