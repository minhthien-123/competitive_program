#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> heads(n);
    vector<int> tracks(m);

    // Đọc vị trí khởi đầu của các đầu đọc
    for (int i = 0; i < n; ++i) {
        cin >> heads[i];
    }

    // Đọc vị trí các track cần đọc
    for (int i = 0; i < m; ++i) {
        cin >> tracks[i];
    }

    // Sắp xếp các track
    sort(tracks.begin(), tracks.end());

    // Thời gian tối thiểu
    int minTime = 0;

    // Sử dụng một queue để theo dõi các đầu đọc
    queue<int> q;
    for (int head : heads) {
        q.push(head);
    }

    // Kiểm tra từng track
    for (int track : tracks) {
        int bestTime = numeric_limits<int>::max();
        int bestHead = -1;

        // Tìm đầu đọc gần nhất có thể đọc track này
        for (int j = 0; j < n; ++j) {
            int head = heads[j];
            int time = abs(head - track);

            if (time < bestTime) {
                bestTime = time;
                bestHead = j;
            }
        }

        // Cập nhật vị trí của đầu đọc đã sử dụng
        heads[bestHead] = track; // Di chuyển đầu đọc đến track đã đọc
        minTime = max(minTime, bestTime); // Cập nhật thời gian tối thiểu
    }

    cout << minTime << endl;

    return 0;
}
