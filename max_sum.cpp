#include <bits/stdc++.h>
using namespace std;

int n;
int arr[10000000];
void findSubArrayMax() {
    cin>>n;
    int best = INT_MIN, sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum = max(arr[i], sum + arr[i]);
        best = max(best, sum);
    }
    cout << best << "\n";
}
int main() {
    findSubArrayMax();
}
