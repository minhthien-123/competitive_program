left_max[1] = sum[1];
        for (int i = 2; i <= m; ++i)
            left_max[i] = max(left_max[i - 1], sum[i]);
        right_max[m] = sum[m];
        for (int i = m - 1; i >= 1; --i)
            right_max[i] = max(right_max[i + 1], sum[i]);