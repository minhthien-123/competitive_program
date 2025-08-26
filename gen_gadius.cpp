#include "testlib.h"
#include <bits/stdc++.h>
#define ll long long

const ll test0 = 15;
const ll test1 = 50;
const ll maxn  = 1e5 + 7;
const std::string task = "C:\\c++\\gladius\\";

ll check(ll mid, ll a[], ll n, ll k)
{
    ll sum = 0;
    ll cnt = 1; // Start with 1 to count the first subarray
    for (int i = 0; i < n; i++) // Change to 0-based indexing
    {
        if (sum + a[i] <= mid)
        {
            sum += a[i];
        }
        else
        {
            sum = a[i]; // Start a new subarray with the current element
            cnt++; // Increase the count of subarrays
        }
    }
    return cnt <= k ? 0 : 1;
}

int main(int argc, char* argv[]){
    registerGen(argc, argv, 1);

    for (ll j = 1; j <= test1; j++)
    {
        std::string tmp = task;
        if (j < 10) tmp += "0";
        tmp = tmp + std::to_string(j);
        CreateDirectory(tmp.c_str(), NULL);
        tmp = tmp + "\\gladius";
        std::ofstream inp(tmp + ".inp");
        std::ofstream out(tmp + ".out");

        // Array declaration
        ll n, k;
        ll a[maxn];

        // Generate test cases
        if (j <= test0) {
            n = rnd.next(1, 1000);
            k = rnd.next(1, 100);
        } else {
            n = rnd.next(50000, 100000);
            k = rnd.next(1, 5000);
        }

        inp << n << " " << k << "\n";

        ll gmin = 0;
        for (int i = 0; i < n; i++) // Ensure correct indexing
        {
            a[i] = rnd.next(1, 1000000);
            inp << a[i] << " ";
            gmin = std::max(a[i], gmin);
        }
        inp << "\n"; // To ensure the last output finishes correctly

        // Binary search for result
        ll ans = -1;
        ll l = gmin;
        ll r = 1e10;
        while (l <= r)
        {
            ll mid = (l + r) / 2;
            ll z = check(mid, a, n, k);
            if (z == 0) {
                r = mid - 1;
                ans = mid; // Update answer here
            } else {
                l = mid + 1;
            }
        }

        std::cout << ans << "\n";
        out << ans << "\n"; // Ensure output ends with a newline

        inp.close();
        out.close();
    }
}