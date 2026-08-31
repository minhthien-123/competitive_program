for (int mask = 0; mask < (1 << m); ++mask)
        {
            if (__builtin_popcount(mask) < N - 1)
                continue;
            vector<int> parent(N + 1);
            iota(parent.begin(), parent.end(), 0);
            ll sum = 0;
            for (int i = 0; i < m; i++)
                if (mask & (1 << i))
                {
                    sum += edges[i].w;
                    int a = findp(parent, edges[i].u);
                    int b = findp(parent, edges[i].v);
                    if (a != b)
                        parent[a] = b;
                }
            int root = findp(parent, 1);
            bool ok = true;
            for (int i = 2; i <= N; i++)
                if (findp(parent, i) != root)
                {
                    ok = false;
                    break;
                }
            if (!ok)
                continue;
            if ((sum & 1) == 0)
                ans = min(ans, sum);
        }