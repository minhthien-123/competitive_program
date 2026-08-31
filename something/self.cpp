## CẶP SỐ BỘI - CPAR

Tác giả: Nguyễn Tiến Nhân( [user:nhangom]) - THPT chuyên Hà Tĩnh


## Tóm tắt đề
Cho hai số nguyên dương ~n~ và ~k~. Hãy đếm số lượng cặp số ~(x, y)~ thỏa mãn ~1 \leq x < y \leq n~ sao cho tổng ~(x + y)~ chia hết cho ~k~.
* Subtask 1: ~1 \leq n \leq 10^3~, ~1 \leq k \leq 10^6~ (70% số điểm)
* Subtask 2: ~1 \leq n \leq 10^9~, ~1 \leq k \leq 10^6~ (30% số điểm)

----------

# Subtask 1 : ~1 \leq n \leq 10^3~, ~1 \leq k \leq 10^6~

## Thuật toán
1. Sử dụng hai vòng lặp lồng nhau để duyệt qua tất cả các cặp ~(x, y)~ thỏa mãn điều kiện ~1 \leq x < y \leq n~.
2. Với mỗi cặp, kiểm tra xem tổng ~(x + y)~ có chia hết cho ~k~ hay không. Nếu có, tăng biến đếm kết quả lên 1.
3. Độ phức tạp là ~O(n^2)~, hoàn toàn vượt qua được giới hạn ~n \leq 10^3~.


## Code
```c++
void sub1()
{
    long long ans = 0;
    for (int x = 1; x <= n; x++)
    {
        for (int y = x + 1; y <= n; y++)
        {
            if ((x + y) % k == 0)
            {
                ans++;
            }
        }
    }
    std::cout << ans << "\n";
}
```
## Subtask 2 : ~1 \leq n \leq 10^9~, ~1 \leq k \leq 10^6~

### Thuật toán
1. Do ~n~ lên tới ~10^9~, ta không thể duyệt trâu. Nhận xét rằng ~(x + y)~ chia hết cho ~k~ khi tổng phần dư của ~x~ và ~y~ chia cho ~k~ bằng ~0~ hoặc bằng ~k~.
2. Sử dụng mảng đếm tần số `cnt`, trong đó `cnt[i]` là số lượng các số trong đoạn từ ~1~ đến ~n~ chia ~k~ dư ~i~. Để mảng bắt đầu từ vị trí 1, nhóm các số chia hết cho ~k~ sẽ được lưu vào `cnt[k]`.
    - Số lượng các số chia ~k~ dư ~i~ (~1 \leq i < k~): ~n / k + (n \bmod k \geq i ? 1 : 0)~.
    - Số lượng các số chia hết cho ~k~: ~n / k~.
3. Kết quả bài toán sẽ là tổng của:
   - Số cách chọn 2 số cùng chia hết cho ~k~: ~cnt[k] \times (cnt[k] - 1) / 2~.
   - Số cách ghép 1 số dư ~i~ và 1 số dư ~k - i~ (với ~1 \leq i < k / 2~): ~cnt[i] \times cnt[k - i]~.
   - Nếu ~k~ chẵn, số cách ghép 2 số cùng dư ~k / 2~: ~cnt[k / 2] \times (cnt[k / 2] - 1) / 2~.

### Code
```c++
void sub2()
{
    std::vector<long long> cnt(k + 1, 0);

    for (int i = 1; i <= k; i++)
    {
        if (i == k)
        {
            cnt[i] = n / k;
        }
        else
        {
            cnt[i] = n / k + (n % k >= i ? 1 : 0);
        }
    }

    long long ans = 0;

    ans += cnt[k] * (cnt[k] - 1) / 2;

    // Ghép 1 số dư i và 1 số dư k - i
    for (int i = 1; i <= (k - 1) / 2; i++)
    {
        ans += cnt[i] * cnt[k - i];
    }

    // Xử lý riêng trường hợp k chẵn
    if (k % 2 == 0)
    {
        long long half = k / 2;
        ans += cnt[half] * (cnt[half] - 1) / 2;
    }

    std::cout << ans << "\n";
}
```