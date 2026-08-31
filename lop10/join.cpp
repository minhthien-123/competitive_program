#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Tìm số viên sỏi nhiều nhất sau khi dồn
    int max_sand = 0;

    // Duyệt qua tất cả các đống
    for (int i = 0; i < n; ++i) {
        // Dồn liên tiếp nếu có thể
        while (i < n - 1 && a[i] == a[i + 1]) {
            // Dồn hai đống liên tiếp có số viên sỏi giống nhau
            a[i] *= 2;
            // Xóa đống thứ i + 1 vì đã dồn
            a.erase(a.begin() + i + 1);
            n--; // Giảm kích thước mảng
            max_sand = max(max_sand, a[i]); // Cập nhật max_sand nếu cần
        }
        max_sand = max(max_sand, a[i]);
    }

    // In kết quả
    cout << max_sand << endl;

    return 0;
}
