#include "testlib.h"
#include <vector>
#include <string>
#include <algorithm>

// Hàm kiểm tra xem có tồn tại 2 phần tử trong mảng arr có tổng bằng S hay không
bool isValidSum(long long S, const std::vector<long long> &arr)
{
    int l = 0, r = (int)arr.size() - 1;
    while (l < r)
    {
        long long current_sum = arr[l] + arr[r];
        if (current_sum == S)
        {
            return true;
        }
        if (current_sum < S)
        {
            l++;
        }
        else
        {
            r--;
        }
    }
    return false;
}

int main(int argc, char *argv[])
{
    // Khởi tạo testlib
    registerTestlibCmd(argc, argv);

    // Đọc input
    int n = inf.readInt();
    int m = inf.readInt();

    std::vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        a[i] = inf.readLong();
    }

    std::vector<long long> b(m);
    for (int i = 0; i < m; i++)
    {
        b[i] = inf.readLong();
    }

    // Sắp xếp mảng để sử dụng thuật toán 2 con trỏ
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    // Đọc token đầu tiên của đáp án và đầu ra thí sinh
    std::string j_first = ans.readString();
    std::string p_first = ouf.readString();

    if (j_first == "no")
    {
        // Ban giám khảo không tìm thấy kết quả
        ans.readString(); // đọc bỏ chữ "volleyball"
        ans.readString(); // đọc bỏ chữ "today"

        if (p_first != "no")
        {
            quitf(_wa, "Jury has no solution, but participant found one: %s", p_first.c_str());
        }

        std::string p_second = ouf.readString();
        std::string p_third = ouf.readString();

        if (p_second != "volleyball" || p_third != "today")
        {
            quitf(_wa, "Expected 'no volleyball today', found something else");
        }

        quitf(_ok, "Correct. No volleyball today.");
    }
    else
    {
        // Ban giám khảo tìm thấy một đáp án hợp lệ
        long long j_ans = std::stoll(j_first);

        if (p_first == "no")
        {
            quitf(_wa, "Jury found a solution (%lld), but participant output 'no volleyball today'", j_ans);
        }

        long long p_ans = 0;
        try
        {
            p_ans = std::stoll(p_first);
        }
        catch (...)
        {
            quitf(_pe, "Expected an integer, but found '%s'", p_first.c_str());
        }

        // Đánh giá tính hợp lệ trong đáp án của thí sinh
        bool ok_a = isValidSum(p_ans, a);
        bool ok_b = isValidSum(p_ans, b);

        if (ok_a && ok_b)
        {
            quitf(_ok, "Valid sum found: %lld", p_ans);
        }
        else
        {
            if (!ok_a && !ok_b)
            {
                quitf(_wa, "Participant answer %lld is not a valid sum in both array A and array B", p_ans);
            }
            else if (!ok_a)
            {
                quitf(_wa, "Participant answer %lld is not a valid sum of two elements in array A", p_ans);
            }
            else
            {
                quitf(_wa, "Participant answer %lld is not a valid sum of two elements in array B", p_ans);
            }
        }
    }

    return 0;
}