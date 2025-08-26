#include <bits/stdc++.h>
#define ll long long
using namespace std;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int N = 1e6 + 9;
const int MOD = 123456789;
ll uoc[N], a[N], n, s = 1;
void sangUoc()
{
    for (int i = 1; i < N; i++)
    {
        for (int j = i; j < N; j += i)
        {
            uoc[j] += 1;
        }
    }
}
void sub2()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s *= a[i];
    }
    if (uoc[s])
        cout << uoc[s] % MOD << " ";
}
int main()
{
    freopen("DIVISOR.inp", "r", stdin);
    freopen("a.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sangUoc();
    sub2();
    return 0;
}