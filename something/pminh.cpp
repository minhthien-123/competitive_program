#include "testlib.h"
#include <bits/stdc++.h>
#define ll long long

// số test
const ll test0 = 15;
const ll test1 = 50;
const ll maxn  = 1e5 + 7;
// path
const std::string task = "C:\\c++\\pminh\\";

ll check(ll mid, ll a[], ll n, ll k)
{
    ll sum=0;
    ll cnt=0;
    for (int i=1;i<=n;i++)
    {
        if (sum+a[i]<=mid)
        {
            sum+=a[i];
        }
        else
        {
            sum=a[i];
            cnt++;
        }
    }
    cnt++;
    if (cnt<=k) return 0;
    return 1;
}
int main(int argc, char* argv[]){
    registerGen(argc, argv, 1);

    for (ll j = 1; j <= test1; j++)
    {
        std::string tmp = task;
        if (j < 10) tmp += "0";
        tmp = tmp + std::to_string(j);
        CreateDirectory(tmp.c_str(), NULL);
        tmp = tmp + "\\pminh";
        std::ofstream inp(tmp + ".inp");
        std::ofstream out(tmp + ".out");

        // khai báo
        ll n, k;
        ll a[maxn];

        // sinh test
        if (j <= test0)
        {
            n = rnd.next(1, 1000);
            k = rnd.next(1, 100);
        }
        else if (j <= test1)
        {
            n = rnd.next(50000, 100000);
            k = rnd.next(1, 5000);
        }

        inp << n << " " << k << "\n";

        ll gmin = 0;
        for (int i = 1; i <= n; i++)
        {
            a[i] = rnd.next(1, 1000000);
            inp << a[i] << " ";
            gmin = std::max(a[i], gmin);
        }

        // code full
        ll ans=-1;
        ll l=gmin;
        ll r=1e10;
        while (l<=r)
        {
            ll mid=(l+r)/2;
            ll z=check(mid, a, n, k);
            if (z==0)
            {
                r=mid-1;
                ans=mid;
            }
            else  l=mid+1;
        }

        std::cout << ans << "\n";
        out << ans;

        inp.close();
        out.close();
    }
}