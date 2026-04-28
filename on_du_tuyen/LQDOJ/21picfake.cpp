#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

struct Painting {
    long long size;
    long long value;
};

bool compare(Painting a, Painting b) {
    return a.size < b.size;
}

int main() {
    int N;
    cin >> N;

    vector<Painting> paintings(N);

    for (int i = 0; i < N; ++i) {
        cin >> paintings[i].size >> paintings[i].value;
    }

    sort(paintings.begin(), paintings.end(), compare);

    priority_queue<long long, vector<long long>, greater<long long>> pq;
    long long current_sum = 0;
    long long max_profit = LLONG_MIN;

    for (int i = 0; i < N; ++i) {
        current_sum += paintings[i].value;
        pq.push(paintings[i].value);

        long long current_profit = current_sum - (paintings[i].size - paintings[0].size);
        max_profit = max(max_profit, current_profit);

        while (!pq.empty() && pq.size() > 1) {
            current_sum -= pq.top();
            pq.pop();
            current_profit = current_sum - (paintings[i].size - paintings[pq.size()].size);
            max_profit = max(max_profit, current_profit);
        }
    }

    cout << max_profit << endl;

    return 0;
}

