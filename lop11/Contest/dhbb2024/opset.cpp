#include <bits/stdc++.h>

const int mod = 1e9 + 7;
std::vector<int> a;
std::unordered_set<int> a_set;
std::vector<int> S;
int n, d, k, max_count = 0, num_ways = 0;

void find_optimal_sets(std::vector<int>& current_set, int index) {
    if (index == S.size()) {
        if (current_set.size() > max_count) {
            max_count = current_set.size();
            num_ways = 1;
        } else if (current_set.size() == max_count) {
            num_ways++;
        }
        return;
    }

    find_optimal_sets(current_set, index + 1);

    bool valid = true;
    for (int num : current_set) {
        if (abs(S[index] - num) <= d) {
            valid = false;
            break;
        }
    }

    if (valid) {
        current_set.push_back(S[index]);
        find_optimal_sets(current_set, index + 1);
        current_set.pop_back();
    }
}

int main() {
    std::cin >> n >> k >> d;
    a.resize(k);
    for (int i = 0; i < k; ++i) {
        std::cin >> a[i];
        a_set.insert(a[i]);
    }

    for (int i = 1; i <= n; ++i) {
        if (a_set.find(i) == a_set.end()) {
            S.push_back(i);
        }
    }

    std::vector<int> current_set;
    find_optimal_sets(current_set, 0);

    std::cout << max_count << "\n" << num_ways % mod;
    return 0;
}
