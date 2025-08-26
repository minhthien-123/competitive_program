#include <bits/stdc++.h>
using namespace std;
const int N = 40 + 2, MaxSize = (1 << 20) + 10;
int n, m;
int w[N], v[N];

long long sumVA[MaxSize];
int sumWA[MaxSize];
int sizeA;

pair<int, long long> B[MaxSize];
int sizeB;
int sumWB[MaxSize];
long long maxSumVB[MaxSize];

void TryX(int i, int sumW, long long sumV) {
    if (sumW > m) return;
    if (i > n / 2) {
        ++sizeA;
        sumWA[sizeA] = sumW;
        sumVA[sizeA] = sumV;
        return;
    }
    TryX(i + 1, sumW, sumV);
    TryX(i + 1, sumW + w[i], sumV + v[i]);
}

void TryY(int i, int sumW, long long sumV) {
    if (sumW > m) return;
    if (i > n) {
        ++sizeB;
        B[sizeB].first  = sumW;
        B[sizeB].second = sumV;
        return;
    }
    TryY(i + 1, sumW, sumV);
    TryY(i + 1, sumW + w[i], sumV + v[i]);
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> w[i] >> v[i];

    TryX(1, 0, 0);
    TryY(n / 2 + 1, 0, 0);
    sort(B + 1, B + sizeB + 1);
    for (int i = 1; i <= sizeB; ++i) {
        sumWB[i]    = B[i].first;
        maxSumVB[i] = max(maxSumVB[i - 1], B[i].second);
    }

    long long maxValue = 0;
    for (int i = 1; i <= sizeA; ++i) {
        int j    = upper_bound(sumWB + 1, sumWB + sizeB + 1, m - sumWA[i]) - sumWB - 1;
        maxValue = max(maxValue, sumVA[i] + maxSumVB[j]);
    }
    cout << maxValue;
}
