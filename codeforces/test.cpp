#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t; // Number of test cases
    cin >> t;

    while (t--) {
        int n; // Number of stamps
        cin >> n;

        vector<pair<int, int>> stamps(n);
        int total_area = 0;

        // Read stamps dimensions
        for (int i = 0; i < n; ++i) {
            cin >> stamps[i].first >> stamps[i].second;
            total_area += stamps[i].first * stamps[i].second; // Calculate total area
        }

        // To minimize perimeter, we want to find the smallest bounding box
        int min_perimeter = INT_MAX;

        // Iterate through possible maximum widths
        for (int width = 1; width <= 100; ++width) {
            for (int height = 1; height <= 100; ++height) {
                if (width * height >= total_area) {
                    int perimeter = 2 * (width + height);
                    min_perimeter = min(min_perimeter, perimeter);
                }
            }
        }

        // Output the minimum perimeter found
        cout << min_perimeter << endl;
    }

    return 0;
}
