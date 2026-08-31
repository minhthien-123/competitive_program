#include "testlib.h"
#include <bits/stdc++.h>
#define ll long long

const int maxn = 3e5 + 7;

// số test
const ll test0 = 20;
const ll test1 = 20;
const ll test2 = 10;
// path
const std::string task = "C:\\c++\\dif\\";

int main(int argc, char* argv[]){
    registerGen(argc, argv, 1);

    for (ll j = 1; j <= (test0 + test1 + test2); j++)
    {
        std::string tmp = task;
        if (j < 10) tmp += "0";
        tmp = tmp + std::to_string(j);
        CreateDirectory(tmp.c_str(), NULL);
        tmp = tmp + "\\dif";
        std::ofstream inp(tmp + ".inp");
        std::ofstream out(tmp + ".out");

        // khai báo
        int n, k;
        int a[maxn];

        // sinh test
        if (j <= test0)
        {
            n = rnd.next(1, 100);
            k = rnd.next(1, n - 1);
        }
        else if (j <= test1)
        {
            n = rnd.next(1, 10000);
            k = rnd.next(n - 100, n - 1);
        }
        else
        {
            n = rnd.next(1, maxn - 1);
            k = rnd.next(1, n - 1);
        }

        inp << n << " " << k << "\n";
        for (int i = 1; i <= n; i++)
        {
            a[i] = rnd.next(1, 1000000000);
            inp << a[i] << " ";
        }

        // code full
        std::set<ll> s;
        std::map<ll, ll> mp;

        for(int i = 1; i <= k; i++)
        {
            s.insert(a[i]);
            mp[a[i]]++;
        }

        ll ans = s.size();
        for (int i = k + 1; i <= n; i++) {
            mp[a[i - k]]--;
            if (!mp[a[i - k]]) s.erase(a[i - k]);
            if (!mp[a[i]]) s.insert(a[i]);
            mp[a[i]]++;
            ans = std::max(ans, (ll)s.size());
        }

        out << ans;

        inp.close();
        out.close();
    }
}