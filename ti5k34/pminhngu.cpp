#include <bits/stdc++.h>
using namespace std;
#define task "main"
#define int long long
#define ll long long
#define ii pair<ll, ll>
#define fi first
#define se second
#define pb push_back
#define ins insert
#define endl "\n"

const int maxn = 2e6 + 7;
vector<ll> g[maxn];
ii a[2000000];
ii b[2000000];
ll ans[2000000];
set<ll> s;
struct cmp{
    bool operator()(ii a,ii b) const
    {

        return a.fi>b.fi;
        return (a.fi==b.fi&&a.se<b.se);
    }
};
ii action[2000000];
multiset<ii,cmp> mts;
ll k,n;
void ip()
{
    cin>>k>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i].fi>>a[i].se;
    }
}
void compress()
{
    vector<ll> t;
    for (int i=1;i<=n;i++)
    {
        t.push_back(a[i].fi);
        t.push_back(a[i].se);
    }
    sort(t.begin(),t.end());
    for (int i=1;i<=n;i++)
    {
        b[i].fi=lower_bound(t.begin(),t.end(),a[i].fi)-t.begin();
        b[i].se=lower_bound(t.begin(),t.end(),a[i].se)-t.begin();
        action[b[i].fi]={1,i};
        action[b[i].se]={-1,i};
    }

}
void process()
{
    s.insert(0ll);
    s.insert(k+1);
    mts.insert({k,1});
    for (auto x:mts)
    {
        cout<<x.fi<<" "<<x.se<<endl;
    }

    for (int i=1;i<=2*n;i++)
    {
        ll checker=action[i].fi;
        ll id=action[i].se;
        if (checker==1)
        {
            ii temp=*mts.begin();
            ll node=(temp.se+temp.fi)/2;
            mts.erase(s.find(temp));
        }
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    if (fopen(task".inp", "r"))
    {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    ip();
    compress();
    process();
}