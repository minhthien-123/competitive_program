#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[])
{
    registerTestlibCmd(argc, argv);

    // 1. Đọc dữ liệu đầu vào (Input) an toàn
    int n = inf.readInt();
    long long p = inf.readLong();

    map<long long, int> original_cnt;
    for (int i = 0; i < n; i++)
    {
        if (inf.seekEof())
        {
            quitf(_fail, "File Input bi thieu du lieu! Expected %d phan tu nhung chi co %d", n, i);
        }
        long long val = inf.readLong();
        original_cnt[val]++;
    }

    // 2. Đọc đáp án chuẩn của Jury (Answer) an toàn
    int dem_ans = -1;
    long long sum_ans = -1;

    // Check xem file đáp án có dữ liệu không, có thì mới đọc
    if (!ans.seekEof())
    {
        dem_ans = ans.readInt();
    }
    if (!ans.seekEof())
    {
        sum_ans = ans.readLong();
    }

    // 3. Đọc đáp án của thí sinh (Output)
    int dem_ouf = ouf.readInt();
    long long sum_ouf = ouf.readLong();

    // 4. So sánh kết quả tối ưu (Chỉ so nếu file Jury có đáp án)
    if (dem_ans != -1 && dem_ouf != dem_ans)
    {
        quitf(_wa, "So luong phan tu con lai khac output chuan. Expected: %d, Found: %d", dem_ans, dem_ouf);
    }
    if (sum_ans != -1 && sum_ouf != sum_ans)
    {
        quitf(_wa, "Tong khac output chuan. Expected: %lld, Found: %lld", sum_ans, sum_ouf);
    }

    // 5. Đọc và xác thực dãy phần tử thí sinh in ra
    map<long long, int> used_cnt;
    long long actual_sum = 0;

    while (!ouf.seekEof())
    {
        long long x = ouf.readLong();
        used_cnt[x]++;
        actual_sum += x;
    }

    if (actual_sum != sum_ouf)
    {
        quitf(_wa, "Tong cac phan tu in ra (%lld) khong khop voi tong da khai bao (%lld)", actual_sum, sum_ouf);
    }

    int actual_dem = 0;
    for (auto const &pair : original_cnt)
    {
        long long val = pair.first;
        int count = pair.second;

        if (used_cnt[val] > count)
        {
            quitf(_wa, "Phan tu %lld duoc su su dung qua so lan cho phep (%d > %d)", val, used_cnt[val], count);
        }
        if (count - used_cnt[val] > 0)
        {
            actual_dem++;
        }
    }

    for (auto const &pair : used_cnt)
    {
        long long val = pair.first;
        if (original_cnt.find(val) == original_cnt.end())
        {
            quitf(_wa, "Phan tu %lld khong ton tai trong mang ban dau", val);
        }
    }

    if (actual_dem != dem_ouf)
    {
        quitf(_wa, "So luong phan tu doc lap con lai tren thuc te (%d) khong khop voi khai bao (%d)", actual_dem, dem_ouf);
    }

    quitf(_ok, "Ket qua hop le! Tong = %lld, Dem = %d", sum_ouf, dem_ouf);
}