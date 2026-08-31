for (int i = 0; i <= n; i++)
    {
        nxt[i][0] = -1;
        nxt[i][1] = -1;
        for (int j = i + 1; j <= n; j++)
        {
            if (nxt[i][0] == -1 && s[j - 1] == 'F')
            {
                nxt[i][0] = j;
            }
            if (nxt[i][1] == -1 && s[j - 1] == 'R')
            {
                nxt[i][1] = j;
            }
        }
    }

    memset(dp, -1, sizeof(dp));

    int start_f = nxt[0][0];
    if (start_f != -1)
    {
        std::cout << f(start_f, 1) << "\n";
    }
    else
    {
        std::cout << 0 << "\n";
    }