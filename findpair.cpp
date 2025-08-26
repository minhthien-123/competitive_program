#include <iostream>

using namespace std;

const int LIM = 1e6 + 16;

int a[LIM];
int main()
{
    int n, x;
    cin >> n >> x;

    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int l = 1, r = n; l < r; ++l)
    {
        while (l < r - 1 && a[l] + a[r] > x) --r;
        if (a[l] + a[r] == x)
        {
            cout << l << ' ' << r;
            return 0;
        }
    }

    cout << "No solution";
    return 0;
}
