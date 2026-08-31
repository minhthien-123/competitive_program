#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
const int N = 2000068;
long long i, j, k, l, n, a[1000168];
long long mod = 10e9 + 7;
map<long long, long long> mp;
void sub1()
{
    long long i, j, k, l, dem = 0;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            for (int k = j + 1; k <= n; k++)
                for (int l = k + 1; l <= n; l++)
                {
                    if (a[i] + a[j] + a[k] == a[l])
                        dem++;
                }
    cout << dem % mod;
}
void sub23()
{
    long long ans = 0;
    for (int i = 2; i <= n - 2; i++)
    {
        for (int j = 1; j <= i - 1; j++)
        {
            mp[a[i] + a[j]]++;
        }
        for (int j = i + 2; j <= n; j++)
        {
            ans = (ans + mp[a[j] - a[i + 1]]) % mod;
        }
    }
    cout << ans % mod;
}
signed main()
{
    //freopen("TSUM.inp","r",stdin);
    //freopen("TSUM.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        //mp[a[i]]++;
    }
        sub23();
}