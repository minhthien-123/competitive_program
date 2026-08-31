#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <numeric> // std::gcd

using namespace std;


struct Point {
    int x;
    int y;
};

vector<Point> points;

int maxPointsOnLine(vector<Point>& points) {
    int n = points.size();
    if (n < 2) return n;

    int maxPoints = 0;

    for (int i = 0; i < n; ++i) {
        unordered_map<string, int> slopeCount;
        int overlap = 0, vertical = 0, currentMax = 0;

        for (int j = i + 1; j < n; ++j) {
            if (points[i].x == points[j].x && points[i].y == points[j].y) {
                overlap++;
                continue;
            }
            if (points[i].x == points[j].x) {
                vertical++;
                continue;
            }

            int dx = points[j].x - points[i].x;
            int g = __gcd(dx, dy);
            int dy = points[j].y - points[i].y;

            dx /= g;
            dy /= g;

            // Ensure consistent representation of slope
            if (dy < 0) {
                dx = -dx;
                dy = -dy;
            }

            string slope = to_string(dy) + '/' + to_string(dx);
            slopeCount[slope]++;
        }

        currentMax = vertical;
        for (auto& pair : slopeCount) {
            currentMax = max(currentMax, pair.second);
        }

        maxPoints = max(maxPoints, currentMax + overlap + 1);
    }

    return maxPoints;
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> points[i];

    cout << "Max points on a line: " << maxPointsOnLine(points) << endl; // Output sẽ là 3
    return 0;
}
