#include <bits/stdc++.h>
using namespace std;

int n, a[1000005];
bool kt[1000005];

void Try(int i)
{
    for (int j = 1; j <= n; j++)
    {
        if (!kt[j])
        {
            kt[j] = true;
            a[i] = j;
            if (i == n)
            {
                for (int k = 1; k <= n; k++)
                    std::cout << a[k] << " ";
                std::cout << "\n";
            }
            else
            {
                Try(i + 1);
            }

            kt[j] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("npermute.inp", "r", stdin);
    //freopen("npermute.out", "w", stdout);

    cin >> n;

    Try(1);
}
