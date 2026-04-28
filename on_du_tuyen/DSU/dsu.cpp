struct DSU
{
    std::vector<int> par, sz;

    DSU(int n)
    {
        par.resize(n + 1);
        sz.assign(n + 1,1);

        for (int i = 0; i <= n; i++)
        {
            par[i] = i;
            sz[i] = 1;
        }
    }

    int acs(int v)
    {
        return v == par[v] ? v : par[v] = acs(par[v]);
    }

    void join(int a, int b)
    {
        a = acs(a);
        b = acs(b);
        if (a != b)
        {
            if (sz[a] < sz[b])
            {
                std::swap(a, b);
            }
            par[b] = a;
            sz[a] += sz[b];
        }
    }
};