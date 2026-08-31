for (int i = 1; i <= n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (dp[j] == -1)
            {
                continue;
            }

            ll sum = P[i] - P[j];

            if (sum > last[j])
            {
                if (dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                    last[i] = sum;
                }
                else if (dp[j] + 1 == dp[i])
                {
                    last[i] = std::min(last[i], sum);
                }
            }
        }
    }
